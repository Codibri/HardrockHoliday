//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /T vs_5_0 /Zi /Od /Gfp /E ShadowMapVS /Fo
//    \\?\C:\Users\INF\Source\Repos\HardrockHolidayU2\resources\Shaders\Cache\Object\Debug\ShadowMapVS.obj
//    /Fe
//    \\?\C:\Users\INF\Source\Repos\HardrockHolidayU2\resources\Shaders\Cache\Error\ShadowMapVS.txt
//    /Fc
//    \\?\C:\Users\INF\Source\Repos\HardrockHolidayU2\resources\Shaders\Cache\Assembly\84f719c6.asm
//    \\?\C:\Users\INF\Source\Repos\HardrockHolidayU2\resources\Shaders\Source\shadowmap.hlsl
//
//
// Buffer Definitions: 
//
// cbuffer ObjectInfo
// {
//
//   float4x4 World;                    // Offset:    0 Size:    64
//   float4x4 LightView;                // Offset:   64 Size:    64
//   float4x4 dummy;                    // Offset:  128 Size:    64 [unused]
//   float4x4 Projection;               // Offset:  192 Size:    64
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// ObjectInfo                        cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// POSITION                 0   xyzw        0     NONE  float   xyzw
// NORMAL                   0   xyz         1     NONE  float       
// TEXCOORD                 0   xy          2     NONE  float       
// TANGENT                  0   xyz         3     NONE  float       
// BITANGENT                0   xyz         4     NONE  float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Position              0   xyzw        0      POS  float   xyzw
//
vs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb0[16], immediateIndexed
dcl_input v0.xyzw
dcl_output_siv o0.xyzw, position
dcl_temps 2

#line 32 "\\?\C:\Users\INF\Source\Repos\HardrockHolidayU2\resources\Shaders\Source\shadowmap.hlsl"
dp4 r0.x, v0.xyzw, cb0[0].xyzw  // output<0:NaN:Inf>
dp4 r0.y, v0.xyzw, cb0[1].xyzw  // output<1:NaN:Inf>
dp4 r0.z, v0.xyzw, cb0[2].xyzw  // output<2:NaN:Inf>
dp4 r0.w, v0.xyzw, cb0[3].xyzw  // output<3:NaN:Inf>
dp4 r1.x, r0.xyzw, cb0[4].xyzw  // output<0:NaN:Inf>
dp4 r1.y, r0.xyzw, cb0[5].xyzw  // output<1:NaN:Inf>
dp4 r1.z, r0.xyzw, cb0[6].xyzw  // output<2:NaN:Inf>
dp4 r1.w, r0.xyzw, cb0[7].xyzw  // output<3:NaN:Inf>
dp4 r0.x, r1.xyzw, cb0[12].xyzw  // output<0:NaN:Inf>
dp4 r0.y, r1.xyzw, cb0[13].xyzw  // output<1:NaN:Inf>
dp4 r0.z, r1.xyzw, cb0[14].xyzw  // output<2:NaN:Inf>
dp4 r0.w, r1.xyzw, cb0[15].xyzw  // output<3:NaN:Inf>
mov o0.xyzw, r0.xyzw  // ShadowMapVS<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf,3:NaN:Inf>
ret 
// Approximately 14 instruction slots used
