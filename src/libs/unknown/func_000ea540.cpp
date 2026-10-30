/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Object000ea540's destructor (slot 0 of its vtable): the array's storage
 * given back. The 0x58-byte class's destructors (0xea380, 0xea440) are
 * emitted here with its vtable, which the builder below stores. */
Object000ea540::~Object000ea540() {}

typedef hkcdDynamicTree::DefaultTree48Storage Tree48; /* derived name */
typedef hkcdDynamicTree::CodecRawUint Tree48Node;     /* derived name */

/* A new leaf put under a tree that has a root: beside the leaf whose union
 * with it is the nearest and smallest, under a new branch from the free
 * list; nothing when the free list cannot grow (its early return leaves the
 * descent's children array without the end of its lifetime, so the array
 * keeps its own slot, as the copy in optimizeTree does). derived name. */
static void insertLeafBelow(Tree48 &tree, u32 leaf, const hkAabb &leafAabb, u32 root)
{
    if (tree.firstFree == 0 && tree.FUN_00022600(1) != HK_SUCCESS) {
        return;
    }
    const u32 branch = tree.firstFree;
    tree.firstFree = reinterpret_cast<const u32 &>(tree.nodes[branch]);
    Tree48Node &branchNode = tree.getNode(branch);

    /* Down to a leaf: each node on the way grows by the new box, and the
     * child whose union with it is the nearer and smaller is taken. */
    Tree48Node *node = &tree.getNode(root);
    if (node->children[0] != 0) {
        const Vec4 center = _mm_add_ps(leafAabb.min, leafAabb.max);
        const Vec4 extent = _mm_sub_ps(leafAabb.max, leafAabb.min);
        do {
            Tree48Node *children[2] = {&tree.getNode(node->children[0]),
                                       &tree.getNode(node->children[1])};
            node->aabb.min = _mm_min_ps(leafAabb.min, node->aabb.min);
            node->aabb.max = _mm_max_ps(leafAabb.max, node->aabb.max);
            Vec4 costs[2];
            for (int i = 0; i < 2; i++) {
                const hkAabb &childAabb = children[i]->aabb;
                const Vec4 offset = _mm_sub_ps(_mm_add_ps(childAabb.min, childAabb.max), center);
                const Vec4 size = _mm_add_ps(extent, _mm_sub_ps(childAabb.max, childAabb.min));
                costs[i] = _mm_mul_ps(_mm_dp_ps(offset, offset, 0x7f),
                                      _mm_dp_ps(size, D_14b2060[3], 0x7f));
            }
            /* The costs compared as scalars by their first lanes. */
            node = children[_mm_ucomigt_ss(costs[0], costs[1])];
        } while (node->children[0] != 0);
    }

    const u32 parent = node->parent;
    if (parent == 0) {
        tree.root = branch;
    } else {
        Tree48Node &parentNode = tree.getNode(parent);
        const u32 nodeIndex = u32(node - tree.nodes.data);
        parentNode.children[parentNode.children[1] == nodeIndex] = branch;
    }
    branchNode.parent = node->parent;
    branchNode.children[0] = u32(node - tree.nodes.data);
    branchNode.children[1] = leaf;
    node->parent = branch;
    tree.getNode(leaf).parent = branch;
    /* The branch's box, the union of the two, built and then stored. */
    hkAabb branchAabb;
    branchAabb.min = _mm_min_ps(leafAabb.min, node->aabb.min);
    branchAabb.max = _mm_max_ps(leafAabb.max, node->aabb.max);
    branchNode.aabb = branchAabb;
}

/* A leaf put into the tree: the root when the tree is empty, else below
 * it. Its box is read before the test (the product of its index shared with
 * the insert's stores). derived name. */
static void insertLeaf(Tree48 &tree, u32 leaf)
{
    Tree48Node &leafNode = tree.getNode(leaf);
    const hkAabb leafAabb = leafNode.aabb;
    const u32 root = tree.root;
    if (root == 0) {
        tree.root = leaf;
        leafNode.parent = 0;
        return;
    }
    insertLeafBelow(tree, leaf, leafAabb, root);
}

/* A leaf for a box and its data, from the free list (grown when empty),
 * inserted. derived name. */
static u32 insert(Tree48 &tree, const hkAabb &aabb, u32 data)
{
    if (tree.firstFree == 0) {
        tree.FUN_00022600(1);
    }
    const u32 leaf = tree.firstFree;
    tree.firstFree = reinterpret_cast<const u32 &>(tree.nodes[leaf]);
    Tree48Node &leafNode = tree.getNode(leaf);
    leafNode.children[0] = 0;
    leafNode.children[1] = data;
    leafNode.aabb = aabb;
    insertLeaf(tree, leaf);
    tree.numLeaves++;
    return leaf;
}

/* The tree rebuilt from its root and, when that succeeds, its nodes
 * copied in order from the root into a new storage that takes its place.
 * derived name. */
static void optimizeTree(Tree48 &tree)
{
    if (tree.FUN_0009db50(tree.root, 1, 32, 16) == HK_SUCCESS && tree.root != 0) {
        Tree48 compact;
        tree.FUN_000bd460(compact);
        tree.nodes.swap(compact.nodes);
        const u32 firstFree = compact.firstFree;
        compact.firstFree = tree.firstFree;
        tree.firstFree = firstFree;
        tree.root = 1;
    }
}

/* A triangle's box inserted as a leaf with its index. derived name. */
static void insertTriangle(Tree48 &tree, const Vec4 *vertices, u32 index)
{
    hkAabb aabb;
    aabb.min = _mm_min_ps(_mm_min_ps(vertices[0], vertices[1]), vertices[2]);
    aabb.max = _mm_max_ps(_mm_max_ps(vertices[0], vertices[1]), vertices[2]);
    insert(tree, aabb, index);
}

/* The geometry's triangles read one at a time into the caller's vertex
 * buffer and inserted, a degenerate one's index listed instead when asked;
 * then the tree optimized. The insertion is this function's first inlined
 * call, so the descent's array is placed after the copy in the builder's
 * frame (the inliner takes a function's first call site first and the rest
 * from the last; each callee's allocas go to the front). derived name. */
static void buildTree(Tree48 &tree, const hknpExternMeshShape::Geometry *geometry, Vec4 *vertices,
                      int numTriangles, const Vec4 &toleranceVector,
                      hkArray<int> *degenerateTriangles)
{
    for (int i = 0; i < numTriangles; i++) {
        geometry->unknownVirtual6(i, vertices);
        if (FUN_00185520(vertices[0], vertices[1], vertices[2], toleranceVector) == 0) {
            insertTriangle(tree, vertices, i);
        } else if (degenerateTriangles) {
            degenerateTriangles->pushBack(i);
        }
    }
    optimizeTree(tree);
}

/* The shape data from the tree: the static tree built from it, and the
 * simd tree from that when asked or when the geometry wants a build
 * context, which it then gets. derived name. */
static hknpExternMeshShapeData *createShapeData(const Tree48 &tree,
                                                const hknpExternMeshShape::Geometry *geometry,
                                                bool buildSimdTree)
{
    hknpExternMeshShapeData *data = new hknpExternMeshShapeData();
    FUN_000dea80(&data->aabbTree, tree);
    data->simdTree.clear();
    if (buildSimdTree || geometry->unknownVirtual8()) {
        FUN_000ded30(&data->simdTree, data->aabbTree);
    }
    if (geometry->unknownVirtual8()) {
        data->buildContext = new Object000ea380();
    }
    return data;
}

/* The tolerance comes before the array (the order of the incoming
 * registers' copies, rdx then xmm0, gives the parameters' order). */
hknpExternMeshShapeData *FUN_000ea610(const hknpExternMeshShape::Geometry *geometry,
                                      bool buildSimdTree, float tolerance,
                                      hkArray<int> *degenerateTriangles)
{
    Tree48 tree;
    Vec4 vertices[3];
    const int numTriangles = geometry->unknownVirtual5();
    const Vec4 toleranceVector = _mm_set1_ps(tolerance);
    tree.FUN_00022600(2 * numTriangles);
    buildTree(tree, geometry, vertices, numTriangles, toleranceVector, degenerateTriangles);
    return createShapeData(tree, geometry, buildSimdTree);
}
