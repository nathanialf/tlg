/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Object000ea540's destructor (slot 0 of its vtable): the array's storage
 * given back. The 0x58-byte class's destructors (0xea380, 0xea440) are
 * emitted here with its vtable, which the builder below stores. */
Object000ea540::~Object000ea540() {}

typedef hkcdDynamicTree::DefaultTree48Storage Tree48; /* derived name */
typedef hkcdDynamicTree::CodecRawUint Tree48Node;     /* derived name */

/* A new leaf put into the tree beside the leaf whose union with it is the
 * nearest and smallest, under a new branch from the free list; nothing when
 * the free list cannot grow. derived name. */
static void insertLeaf(Tree48 &tree, u32 leaf)
{
    Tree48Node &leafNode = tree.getNode(leaf);
    const u32 root = tree.root;
    if (root == 0) {
        tree.root = leaf;
        leafNode.parent = 0;
        return;
    }
    const hkAabb leafAabb = leafNode.aabb;
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
        const Vec4 extent = _mm_sub_ps(leafAabb.max, leafAabb.min);
        const Vec4 center = _mm_add_ps(leafAabb.min, leafAabb.max);
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
            node = children[_mm_cvtss_f32(costs[0]) > _mm_cvtss_f32(costs[1])];
        } while (node->children[0] != 0);
    }

    const u32 parent = node->parent;
    if (parent == 0) {
        tree.root = branch;
    } else {
        Tree48Node &parentNode = tree.getNode(parent);
        parentNode.children[parentNode.children[1] == u32(node - tree.nodes.data)] = branch;
    }
    branchNode.parent = node->parent;
    branchNode.children[0] = u32(node - tree.nodes.data);
    branchNode.children[1] = leaf;
    node->parent = branch;
    tree.getNode(leaf).parent = branch;
    branchNode.aabb.min = _mm_min_ps(leafAabb.min, node->aabb.min);
    branchNode.aabb.max = _mm_max_ps(leafAabb.max, node->aabb.max);
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

/* The shape data from a tree of the geometry's triangles: the tree rebuilt
 * and, when that succeeds, its nodes copied in order from the root into a
 * new storage that takes its place; then the static tree built from it, and
 * the simd tree from that when asked or when the geometry wants a build
 * context, which it then gets. derived name. */
static hknpExternMeshShapeData *
createShapeData(Tree48 &tree, const hknpExternMeshShape::Geometry *geometry, bool buildSimdTree)
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

// NONMATCHING: 0xea610 is 26 normalized lines from the base (frame
// offsets masked). Its frame order is the base's (the copy -0x50, the
// descent's children -0x60, the tree -0x80, the vertices -0xb0, the
// tolerance -0xc0: the copy's helper inlined after the insert, its alloca
// spliced in front), but StackColoring merges the children into the copy's
// slot (both carry the inliner's markers, disjoint: 3.3
// StackColoring.cpp:741-779) where the base keeps both. Left besides: the
// leaf block multiplies the leaf's index by 48 shift first (the multiply not
// a single add's operand, X86ISelLowering.cpp:16185) and the box's read back
// reuses it, where this source multiplies lea first and MachineCSE shares
// one product with every path; the register and spill choices that follow
// (docs/NOTES.md, Round 58).
hknpExternMeshShapeData *FUN_000ea610(const hknpExternMeshShape::Geometry *geometry,
                                      bool buildSimdTree, hkArray<int> *degenerateTriangles,
                                      float tolerance)
{
    Tree48 tree;
    Vec4 vertices[3];
    const int numTriangles = geometry->unknownVirtual5();
    const Vec4 toleranceVector = _mm_set1_ps(tolerance);
    tree.FUN_00022600(2 * numTriangles);
    for (int i = 0; i < numTriangles; i++) {
        geometry->unknownVirtual6(i, vertices);
        if (FUN_00185520(vertices[0], vertices[1], vertices[2], toleranceVector) == 0) {
            hkAabb aabb;
            aabb.min = _mm_min_ps(_mm_min_ps(vertices[0], vertices[1]), vertices[2]);
            aabb.max = _mm_max_ps(_mm_max_ps(vertices[0], vertices[1]), vertices[2]);
            insert(tree, aabb, i);
        } else if (degenerateTriangles) {
            degenerateTriangles->pushBack(i);
        }
    }

    return createShapeData(tree, geometry, buildSimdTree);
}
