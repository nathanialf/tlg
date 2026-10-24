# Survey of `baserom/base/eboot.elf`

| | |
|---|---|
| file size | 92,706,009 bytes |
| ELF type | 0xFE10 (ET_SCE_DYNEXEC) |
| entry | 0xA0 |
| SDK (PT_SCE_PROCPARAM) | 03.508.031 (0x03508031) |
| original output path (PT_SCE_COMMENT) | `D:/trico/engine/anzu/bin/ps4/launch_tricom.elf` |
| .text segment | vaddr 0x0, 23,635,436 bytes |
| functions (FDEs) | 19,733 |
| bytes in functions | 21,488,900 (90.9% of .text) |
| gaps between functions | 203,553 bytes |
| function size min / median / max | 1 / 263 / 378,258 |
| dynamic symbols | 510 (508 imports, 503 functions; 0 exports) |
| relocations | 29,413 RELA + 503 JMPREL |
| needed modules | 23 |
| import libraries | 24 |
| source files named in strings | 119 |

## Program headers

| # | type | offset | vaddr | filesz | memsz | flags |
|---|---|---|---|---|---|---|
| 0 | PT_LOAD | 0x4000 | 0x0 | 0x168A5EC | 0x168A5EC | 5 |
| 1 | PT_SCE_RELRO | 0x1690000 | 0x168C000 | 0x4D148 | 0x50000 | 4 |
| 2 | PT_LOAD | 0x16E0000 | 0x16DC000 | 0x40D3288 | 0x4406D10 | 6 |
| 3 | PT_SCE_PROCPARAM | 0x16E0000 | 0x16DC000 | 0x48 | 0x48 | 4 |
| 4 | PT_DYNAMIC | 0x5868498 | 0x0 | 0x7E0 | 0x7E0 | 6 |
| 5 | PT_INTERP | 0x4000 | 0x0 | 0x15 | 0x15 | 4 |
| 6 | PT_TLS | 0x16E0060 | 0x16DC060 | 0x4 | 0x70 | 4 |
| 7 | PT_GNU_EH_FRAME | 0x1667D38 | 0x1663D38 | 0x268B4 | 0x268B4 | 4 |
| 8 | PT_SCE_DYNLIBDATA | 0x57B3300 | 0x0 | 0xB5978 | 0x0 | 4 |
| 9 | PT_SCE_COMMENT | 0x5868C80 | 0x0 | 0x3C | 0x0 | 0 |
| 10 | PT_SCE_LIBVERSION | 0x5868CBC | 0x0 | 0x81D | 0x0 | 0 |

## Needed modules

- `libSceCommonDialog`
- `libSceMsgDialog`
- `libSceSysmodule`
- `libSceVideoOut`
- `libSceGnmDriver`
- `libScePad`
- `libkernel`
- `libSceNet`
- `libSceNetCtl`
- `libSceAudioOut`
- `libSceNgs2`
- `libSceSaveData`
- `libSceUserService`
- `libSceFios2`
- `libScePlayGo`
- `libScePlayGoDialog`
- `libSceNpCommon`
- `libSceNpManager`
- `libSceNpTrophy`
- `libSceAppContentUtil`
- `libc`
- `libSceSystemService`
- `libSceAudio3d`

## Import libraries

- `libSceAppContent`
- `libSceAudio3d`
- `libSceAudioOut`
- `libSceCommonDialog`
- `libSceFios2`
- `libSceGnmDriver`
- `libSceMsgDialog`
- `libSceNet`
- `libSceNetCtl`
- `libSceNgs2`
- `libSceNpCommon`
- `libSceNpManager`
- `libSceNpTrophy`
- `libScePad`
- `libScePlayGo`
- `libScePlayGoDialog`
- `libSceSaveData`
- `libSceSysmodule`
- `libSceSystemService`
- `libSceUserService`
- `libSceVideoOut`
- `libc`
- `libScePosix`
- `libkernel`

## Exports


## Linked libraries (PT_SCE_LIBVERSION)

- `crt1 03508031`
- `crti 03508031`
- `crtbegin 03508031`
- `crtend 03508031`
- `crtn 03508031`
- `libSceGnf 03508031`
- `libSceGpuAddress 03508201`
- `libSceGpuAddress 03508201`
- `libSceGpuAddress 03508201`
- `libSceGpuAddress 03508201`
- `libSceShaderBinary 03508031`
- `libSceCommonDialog_stub_weak 03508031`
- `libSceMsgDialog_stub_weak 03508031`
- `libSceSysmodule_stub_weak 03508031`
- `libSceVideoOut_stub_weak 03508031`
- `libSceGnmDriver_stub_weak 03508201`
- `libScePad_stub_weak 03508031`
- `libScePosix_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNetCtl_stub_weak 03508031`
- `libSceAudioOut_stub_weak 03508031`
- `libSceNgs2_stub_weak 03508031`
- `libSceSaveData_stub_weak 03508031`
- `libSceUserService_stub_weak 03508031`
- `libSceFios2_stub_weak 03508031`
- `libScePlayGo_stub_weak 03508031`
- `libScePlayGoDialog_stub_weak 03508031`
- `libSceNpCommon_stub_weak 03508031`
- `libSceNpManager_stub_weak 03508031`
- `libSceNpTrophy_stub_weak 03508031`
- `libSceAppContent_stub_weak 03508031`
- `libkernel_stub_weak 03508101`
- `libc_stub_weak 03508031`
- `libSceSystemService_stub_weak 03508201`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceAudio3d_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceNet_stub_weak 03508031`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`
- `libSceGnm_lto 03508211`

## Source roots named in strings

| root | files |
|---|---|
| `D:/trico/engine` | 71 |
| `Y:/NightlyJobs/20141121-01` | 22 |
| `C:/sound/sndx` | 20 |
| `C:/Program Files (x86)/SCE` | 5 |
| `C:/Work/P4` | 1 |

## Source files


### `C:/Program Files (x86)/SCE`

- `C:/Program Files (x86)/SCE/ORBIS SDKs/3.500/target/include_common/gnm/depthrendertarget.h`
- `C:/Program Files (x86)/SCE/ORBIS SDKs/3.500/target/include_common/gnm/rendertarget.h`
- `C:/Program Files (x86)/SCE/ORBIS SDKs/3.500/target/include_common/gnm/sampler.h`
- `C:/Program Files (x86)/SCE/ORBIS SDKs/3.500/target/include_common/gnm/shader.h`
- `C:/Program Files (x86)/SCE/ORBIS SDKs/3.500/target/include_common/gnm/texture.h`

### `C:/Work/P4`

- `C:/Work/P4/depot/Release/2014_2/2014_2_0_Release/Source/Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHull.cpp`

### `C:/sound/sndx`

- `C:/sound/sndx/trico/runtime/source/sndx/sndx_audioout_orbis.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_buss_fx.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_engine_ngs2_orbis.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_helpers.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_instance.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_player.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_player_dynamic_stream.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_player_morph.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_player_sequence.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_player_trans.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_player_wave.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_resource.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_stream.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_system.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_variable.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_voice.c`
- `C:/sound/sndx/trico/runtime/source/sndx/sndx_xfader.c`
- `C:/sound/sndx/trico/runtime/source/sndxs_file/sndxs_file_instance.c`
- `C:/sound/sndx/trico/runtime/source/sndxs_file/sndxs_file_request.c`
- `C:/sound/sndx/trico/runtime/source/sndxs_file/sndxs_file_system.c`

### `D:/trico/engine`

- `D:/trico/engine/anzu/engine_src/engine/particle/Particle_Buffer.cpp`
- `D:/trico/engine/anzu/engine_src/props/../../external/ps4/include_common/gnmx/helpers.h`
- `D:/trico/engine/anzu/engine_src/props/../render/ps4/JsDeviceContextInline.h`
- `D:/trico/engine/anzu/engine_src/props/../render/ps4/util/condition_variable.h`
- `D:/trico/engine/anzu/engine_src/props/../render/ps4/util/mutex.h`
- `D:/trico/engine/anzu/engine_src/render/dev/../ps4/JsDeviceContextInline.h`
- `D:/trico/engine/anzu/engine_src/render/dev/AabbCompute.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/AmbientLighting.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/Bloom.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/ComputeInterface.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/InstanceBufferCompute.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/LightBuffer.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/PostProcess.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/RayCastCompute.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/RenderTarget.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/RendererDev_Setup.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/RendererLightProbeArray.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/SMAA.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/SSAO.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/Skinning.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/TileCull.cpp`
- `D:/trico/engine/anzu/engine_src/render/dev/TrackingCompute.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsDevice.h`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsDeviceContextInline.h`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsVolatileMemory.h`
- `D:/trico/engine/anzu/engine_src/render/ps4/util/condition_variable.h`
- `D:/trico/engine/anzu/engine_src/render/ps4/util/misc.h`
- `D:/trico/engine/anzu/engine_src/render/ps4/util/mutex.h`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsBlendState.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsBuffer.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsComputeContext.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsComputeQueue.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsDepthStencilState.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsDepthStencilView.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsDevice.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsDeviceContext.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsGraphics.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsInputLayout.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsPixelShader.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsRasterizerState.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsRenderTargetView.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsSamplerState.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsShaderResourceView.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsSwapChain.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsTex.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsTexture.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsTexture1D.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsTexture2D.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsTexture3D.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsUnknown.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsUnorderedAccessView.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsVertexShader.cpp`
- `D:/trico/engine/anzu/engine_src/render/ps4/JsView.cpp`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/Debugger/../Platform/String/../../virtualMachine/Kernel/../../virtualMachine/lua_impl.inl`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/Debugger/../Platform/String/../../virtualMachine/MetaTable.h`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/Debugger/../Platform/String/../../virtualMachine/String/../Memory/MemoryManager.h`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/Debugger/NetworkDebugger.cpp`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/Compiler/../utils.h`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/Compiler/../vm-core.inl`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/Compiler/BytecodeReader.cpp`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/Debug/vm-debug.cpp`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/Memory/GarbageCollector.cpp`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/Memory/GarbageCollectorWeights.cpp`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/Profile/hksProfiler.cpp`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/hksObject.cpp`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/ksTable/Table.cpp`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/lib/lib-package.cpp`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/vm-aux.cpp`
- `D:/trico/engine/anzu/external/havok/HavokScriptVM-2013.3.0/build/../source/virtualMachine/vm-core.cpp`
- `D:/trico/engine/anzu/external/ps4/src/gnmx/gfxcontext.cpp`
- `D:/trico/engine/anzu/src/game/entity/ElectricityEffect.cpp`

### `Y:/NightlyJobs/20141121-01`

- `Y:/NightlyJobs/20141121-01/Source/Common/Base/Memory/System/FreeList/hkFreeListMemorySystem.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Common/Base/System/Error/hkError.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Common/Base/System/Hardware/hkHardwareInfo.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Common/Base/System/Io/Platform/Ps4/hkPs4StreamWriter.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Common/Base/Thread/Thread/Posix/hkPosixThread.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Common/GeometryUtilities/Mesh/Skin/hkSkinnedMeshShape.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Common/GeometryUtilities/Mesh/Utils/VertexBufferUtil/hkMeshVertexBufferUtil.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Common/Serialize/Copier/hkObjectCopier.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Common/Serialize/Packfile/hkPackfileWriter.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Common/Serialize/ResourceDatabase/hkResourceHandle.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Common/Serialize/Util/hkSerializeUtil.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Common/Serialize/Util/hkStructureLayout.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Geometry/Internal/DataStructures/SimdTree/hkcdSimdTree.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Physics/Internal/Collide/Shape/Composite/Mesh/Compressed/hknpCompressedMeshShape.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Physics/Internal/Dynamics/Solver/Scheduler/hknpSolverScheduler.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Physics/Physics/Collide/Dispatcher/hknpCollisionDispatcher.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Physics/Physics/Collide/Shape/Convex/Polytope/hknpConvexPolytopeShape.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Physics/Physics/Collide/Shape/hknpShape.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Physics/Physics/Dynamics/Body/hknpBodyManager.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Physics/Physics/Dynamics/Constraint/hknpConstraintManager.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Physics/Physics/Dynamics/Motion/hknpMotionManager.cpp`
- `Y:/NightlyJobs/20141121-01/Source/Physics/Physics/Dynamics/World/hknpWorld.cpp`
