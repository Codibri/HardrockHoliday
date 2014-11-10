//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
// Buffer Definitions: 
//
// cbuffer ObjectInfo
// {
//
//   float4x4 World;                    // Offset:    0 Size:    64
//   float4x4 View;                     // Offset:   64 Size:    64
//   float4x4 ViewInv;                  // Offset:  128 Size:    64
//   float4x4 Projection;               // Offset:  192 Size:    64
//   uint4 iLightsAffecting;            // Offset:  256 Size:    16
//   uint iLightCount;                  // Offset:  272 Size:     4
//
// }
//
// Resource bind info for Lights
// {
//
//   struct Light
//   {
//       
//       float3 f3Position;             // Offset:    0
//       uint iType;                    // Offset:   12
//       float4 f4Color;                // Offset:   16
//       float3 f3Direction;            // Offset:   32
//       float fInnerCosAngle;          // Offset:   44
//       float fOuterCosAngle;          // Offset:   48
//       float fAttenuationConstant;    // Offset:   52
//       float fAttenuationLinear;      // Offset:   56
//       float fAttenuationQuadratic;   // Offset:   60
//       bool bCauseShadow;             // Offset:   64
//       bool bSoftShadow;              // Offset:   68
//       bool bCascadedShadow;          // Offset:   72
//       float4x4 mLightViewProj;       // Offset:   76
//
//   } $Element;                        // Offset:    0 Size:   140
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// Lights                            texture  struct         r/o   10        1
// ObjectInfo                        cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// POSITION                 0   xyzw        0     NONE  float   xyzw
// NORMAL                   0   xyz         1     NONE  float   xyz 
// TEXCOORD                 0   xy          2     NONE  float   xy  
// TANGENT                  0   xyz         3     NONE  float   xyz 
// BITANGENT                0   xyz         4     NONE  float   xyz 
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float   xyzw
// NORMAL                   0   xyz         1     NONE  float   xyz 
// LIGHTS                   5      w        1     NONE  float      w
// TANGENT                  0   xyz         2     NONE  float   xyz 
// LIGHTS                  16      w        2     NONE  float      w
// BITANGENT                0   xyz         3     NONE  float   xyz 
// LIGHTS                  17      w        3     NONE  float      w
// TEXCOORD                 0   xy          4     NONE  float   xy  
// LIGHTS                   4     zw        4     NONE  float     zw
// TEXCOORD                 1   xyz         5     NONE  float   xyz 
// LIGHTS                  29      w        5     NONE  float      w
// TEXCOORD                 2   xyzw        6     NONE  float   xyzw
// LIGHTS                   0   xyzw        7     NONE  float   xyzw
// LIGHTS                   2   xyzw        8     NONE  float   xyzw
// LIGHTS                   3   xyzw        9     NONE  float   xyzw
// LIGHTS                   6   xyzw       10     NONE   uint   xyzw
// LIGHTS                  10   xyzw       11     NONE   uint   xyzw
// LIGHTS                  11   xyzw       12     NONE  float   xyzw
// LIGHTS                  12   xyzw       13     NONE  float   xyzw
// LIGHTS                  14   xyzw       14     NONE  float   xyzw
// LIGHTS                  15   xyzw       15     NONE  float   xyzw
// LIGHTS                  21   xyzw       16     NONE   uint   xyzw
// LIGHTS                  23   xyzw       17     NONE  float   xyzw
// LIGHTS                  24   xyzw       18     NONE  float   xyzw
// LIGHTS                  26   xyzw       19     NONE  float   xyzw
// LIGHTS                  27   xyz        20     NONE  float   xyz 
// LIGHTS                  32   xyzw       21     NONE   uint   xyzw
// LIGHTS                  35   xyzw       22     NONE  float   xyzw
// LIGHTS                  36   xyzw       23     NONE  float   xyzw
// LIGHTS                  38   xyzw       24     NONE  float   xyzw
// LIGHTS                  39   xyz        25     NONE  float   xyz 
// LIGHTS                  43   xyzw       26     NONE   uint   xyzw
// LIGHTS                  47   xyzw       27     NONE  float   xyzw
// COUNT                    0   x          28     NONE   uint   x   
//
vs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb0[18], immediateIndexed
dcl_resource_structured t10, 140 
dcl_input v0.xyzw
dcl_input v1.xyz
dcl_input v2.xy
dcl_input v3.xyz
dcl_input v4.xyz
dcl_output_siv o0.xyzw, position
dcl_output o1.xyz
dcl_output o1.w
dcl_output o2.xyz
dcl_output o2.w
dcl_output o3.xyz
dcl_output o3.w
dcl_output o4.xy
dcl_output o4.zw
dcl_output o5.xyz
dcl_output o5.w
dcl_output o6.xyzw
dcl_output o7.xyzw
dcl_output o8.xyzw
dcl_output o9.xyzw
dcl_output o10.xyzw
dcl_output o11.xyzw
dcl_output o12.xyzw
dcl_output o13.xyzw
dcl_output o14.xyzw
dcl_output o15.xyzw
dcl_output o16.xyzw
dcl_output o17.xyzw
dcl_output o18.xyzw
dcl_output o19.xyzw
dcl_output o20.xyz
dcl_output o21.xyzw
dcl_output o22.xyzw
dcl_output o23.xyzw
dcl_output o24.xyzw
dcl_output o25.xyz
dcl_output o26.xyzw
dcl_output o27.xyzw
dcl_output o28.x
dcl_temps 34
dp4 r0.x, v0.xyzw, cb0[0].xyzw
dp4 r0.y, v0.xyzw, cb0[1].xyzw
dp4 r0.z, v0.xyzw, cb0[2].xyzw
dp4 r0.w, v0.xyzw, cb0[3].xyzw
mov r1.y, r0.x
mov r1.z, r0.y
mov r1.w, r0.z
mov r2.w, r0.w
mov r2.xyz, r1.yzwy
if_nz cb0[17].x
  mov r3.w, cb0[16].x
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r4.y, r3.w, l(0), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r4.z, r3.w, l(4), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r4.w, r3.w, l(8), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r3.x, r3.w, l(12), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r5.x, r3.w, l(16), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r5.y, r3.w, l(20), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r5.z, r3.w, l(24), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r5.w, r3.w, l(28), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r6.x, r3.w, l(32), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r6.y, r3.w, l(36), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r6.z, r3.w, l(40), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r6.w, r3.w, l(44), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r7.w, r3.w, l(48), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r1.x, r3.w, l(52), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r4.x, r3.w, l(56), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r8.x, r3.w, l(60), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r8.y, r3.w, l(64), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r8.z, r3.w, l(68), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r8.w, r3.w, l(72), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r9.x, r3.w, l(76), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r9.y, r3.w, l(92), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r9.z, r3.w, l(108), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r9.w, r3.w, l(124), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r10.x, r3.w, l(80), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r10.y, r3.w, l(96), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r10.z, r3.w, l(112), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r10.w, r3.w, l(128), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r11.x, r3.w, l(84), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r11.y, r3.w, l(100), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r11.z, r3.w, l(116), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r11.w, r3.w, l(132), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r12.x, r3.w, l(88), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r12.y, r3.w, l(104), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r12.z, r3.w, l(120), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r12.w, r3.w, l(136), t10.xxxx
  ine r7.x, l(0, 0, 0, 0), r8.y
  ine r7.y, l(0, 0, 0, 0), r8.z
  ine r7.z, l(0, 0, 0, 0), r8.w
  mov r5.x, r5.x
  mov r5.y, r5.y
  mov r5.z, r5.z
  mov r5.w, r5.w
  mov r4.y, r4.y
  mov r4.z, r4.z
  mov r4.w, r4.w
  mov r6.x, r6.x
  mov r6.y, r6.y
  mov r6.z, r6.z
  mov r6.w, r6.w
  mov r7.w, r7.w
  mov r4.x, r4.x
  mov r8.x, r8.x
  mov r3.x, r3.x
  mov r1.x, r1.x
  mov r3.w, r3.w
  mov r5.xyzw, r5.xyzw
  mov r7.x, r7.x
  ieq r8.y, r3.x, l(3)
  if_nz r8.y
    mov r8.yzw, -r1.yyzw
    add r8.yzw, r4.yyzw, r8.yyzw
    dp3 r13.x, r8.yzwy, r8.yzwy
    rsq r13.y, r13.x
    mul r14.yzw, r8.yyzw, r13.yyyy
    mov r6.xyz, r6.xyzx
    mov r6.w, r6.w
    mov r7.w, r7.w
    sqrt r8.y, r13.x
    mov r8.z, -r8.y
    max r8.y, r8.z, r8.y
    add r8.z, r1.x, l(1.000000)
    mul r8.w, r4.x, r8.y
    add r8.z, r8.w, r8.z
    max r8.y, r8.y, l(1.000000)
    mul r8.y, r8.y, r8.y
    mul r8.y, r8.y, l(1.000000)
    mul r8.y, r8.y, r8.x
    add r8.y, r8.y, r8.z
    div r14.x, l(1.000000), r8.y
    mul r13.xyzw, r9.xxxx, cb0[0].xyzw
    mul r15.xyzw, r10.xxxx, cb0[1].xyzw
    add r13.xyzw, r13.xyzw, r15.xyzw
    mul r15.xyzw, r11.xxxx, cb0[2].xyzw
    add r13.xyzw, r13.xyzw, r15.xyzw
    mul r15.xyzw, r12.xxxx, cb0[3].xyzw
    add r13.xyzw, r13.xyzw, r15.xyzw
    mul r15.xyzw, r9.yyyy, cb0[0].xyzw
    mul r16.xyzw, r10.yyyy, cb0[1].xyzw
    add r15.xyzw, r15.xyzw, r16.xyzw
    mul r16.xyzw, r11.yyyy, cb0[2].xyzw
    add r15.xyzw, r15.xyzw, r16.xyzw
    mul r16.xyzw, r12.yyyy, cb0[3].xyzw
    add r15.xyzw, r15.xyzw, r16.xyzw
    mul r16.xyzw, r9.zzzz, cb0[0].xyzw
    mul r17.xyzw, r10.zzzz, cb0[1].xyzw
    add r16.xyzw, r16.xyzw, r17.xyzw
    mul r17.xyzw, r11.zzzz, cb0[2].xyzw
    add r16.xyzw, r16.xyzw, r17.xyzw
    mul r17.xyzw, r12.zzzz, cb0[3].xyzw
    add r16.xyzw, r16.xyzw, r17.xyzw
    mul r9.xyzw, r9.wwww, cb0[0].xyzw
    mul r10.xyzw, r10.wwww, cb0[1].xyzw
    add r9.xyzw, r9.xyzw, r10.xyzw
    mul r10.xyzw, r11.wwww, cb0[2].xyzw
    add r9.xyzw, r9.xyzw, r10.xyzw
    mul r10.xyzw, r12.wwww, cb0[3].xyzw
    add r9.xyzw, r9.xyzw, r10.xyzw
    dp4 r10.y, v0.xyzw, r13.xyzw
    dp4 r10.w, v0.xyzw, r15.xyzw
    dp4 r10.z, v0.xyzw, r16.xyzw
    dp4 r10.x, v0.xyzw, r9.xyzw
    mov r7.y, r7.y
    mov r7.z, r7.z
    mov r3.yz, r10.yywy
  else 
    ieq r8.y, r3.x, l(2)
    if_nz r8.y
      mov r8.yzw, -r1.yyzw
      add r4.yzw, r4.yyzw, r8.yyzw
      dp3 r8.y, r4.yzwy, r4.yzwy
      rsq r8.z, r8.y
      mul r14.yzw, r4.yyzw, r8.zzzz
      sqrt r4.y, r8.y
      mov r4.z, -r4.y
      max r4.y, r4.z, r4.y
      add r1.x, r1.x, l(1.000000)
      mul r4.x, r4.y, r4.x
      add r1.x, r1.x, r4.x
      max r4.x, r4.y, l(1.000000)
      mul r4.x, r4.x, r4.x
      mul r4.x, r4.x, l(1.000000)
      mul r4.x, r4.x, r8.x
      add r1.x, r1.x, r4.x
      div r14.x, l(1.000000), r1.x
    else 
      mov r14.yzw, r6.xxyz
      mov r14.x, l(1.000000)
    endif 
    mov r6.xyzw, l(0,0,0,0)
    mov r7.yzw, l(0,0,0,0)
    mov r3.yz, l(0,0,0,0)
    mov r10.xz, l(0,0,0,0)
  endif 
  mov r3.x, r3.x
else 
  mov r14.xyzw, l(0,0,0,0)
  mov r5.xyzw, l(0,0,0,0)
  mov r6.xyzw, l(0,0,0,0)
  mov r7.xyzw, l(0,0,0,0)
  mov r3.xyzw, l(0,0,0,0)
  mov r10.xz, l(0,0,0,0)
endif 
ult r1.x, l(1), cb0[17].x
if_nz r1.x
  mov r4.x, cb0[16].y
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r8.y, r4.x, l(0), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r8.z, r4.x, l(4), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r8.w, r4.x, l(8), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r4.y, r4.x, l(12), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r9.x, r4.x, l(16), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r9.y, r4.x, l(20), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r9.z, r4.x, l(24), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r9.w, r4.x, l(28), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r11.x, r4.x, l(32), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r11.y, r4.x, l(36), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r11.z, r4.x, l(40), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r11.w, r4.x, l(44), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r12.w, r4.x, l(48), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r1.x, r4.x, l(52), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r8.x, r4.x, l(56), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r10.y, r4.x, l(60), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r10.w, r4.x, l(64), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r13.x, r4.x, l(68), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r13.y, r4.x, l(72), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r13.z, r4.x, l(76), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r13.w, r4.x, l(92), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r15.x, r4.x, l(108), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r15.y, r4.x, l(124), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r15.z, r4.x, l(80), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r15.w, r4.x, l(96), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r16.x, r4.x, l(112), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r16.y, r4.x, l(128), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r16.z, r4.x, l(84), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r16.w, r4.x, l(100), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r17.x, r4.x, l(116), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r17.y, r4.x, l(132), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r17.z, r4.x, l(88), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r17.w, r4.x, l(104), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r18.x, r4.x, l(120), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r18.y, r4.x, l(136), t10.xxxx
  ine r12.x, l(0, 0, 0, 0), r10.w
  ine r12.y, l(0, 0, 0, 0), r13.x
  ine r12.z, l(0, 0, 0, 0), r13.y
  mov r9.x, r9.x
  mov r9.y, r9.y
  mov r9.z, r9.z
  mov r9.w, r9.w
  mov r8.y, r8.y
  mov r8.z, r8.z
  mov r8.w, r8.w
  mov r11.x, r11.x
  mov r11.y, r11.y
  mov r11.z, r11.z
  mov r11.w, r11.w
  mov r12.w, r12.w
  mov r8.x, r8.x
  mov r10.y, r10.y
  mov r4.y, r4.y
  mov r1.x, r1.x
  mov r4.x, r4.x
  mov r9.xyzw, r9.xyzw
  mov r12.x, r12.x
  ieq r10.w, r4.y, l(3)
  if_nz r10.w
    mov r19.xyz, -r1.yzwy
    add r19.xyz, r8.yzwy, r19.xyzx
    dp3 r10.w, r19.xyzx, r19.xyzx
    rsq r13.x, r10.w
    mul r19.yzw, r13.xxxx, r19.xxyz
    mov r11.xyz, r11.xyzx
    mov r11.w, r11.w
    mov r12.w, r12.w
    sqrt r10.w, r10.w
    mov r13.x, -r10.w
    max r10.w, r10.w, r13.x
    add r13.x, r1.x, l(1.000000)
    mul r13.y, r8.x, r10.w
    add r13.x, r13.y, r13.x
    max r10.w, r10.w, l(1.000000)
    mul r10.w, r10.w, r10.w
    mul r10.w, r10.w, l(1.000000)
    mul r10.w, r10.w, r10.y
    add r10.w, r10.w, r13.x
    div r19.x, l(1.000000), r10.w
    mul r20.xyzw, r13.zzzz, cb0[0].xyzw
    mul r21.xyzw, r15.zzzz, cb0[1].xyzw
    add r20.xyzw, r20.xyzw, r21.xyzw
    mul r21.xyzw, r16.zzzz, cb0[2].xyzw
    add r20.xyzw, r20.xyzw, r21.xyzw
    mul r21.xyzw, r17.zzzz, cb0[3].xyzw
    add r20.xyzw, r20.xyzw, r21.xyzw
    mul r13.xyzw, r13.wwww, cb0[0].xyzw
    mul r21.xyzw, r15.wwww, cb0[1].xyzw
    add r13.xyzw, r13.xyzw, r21.xyzw
    mul r21.xyzw, r16.wwww, cb0[2].xyzw
    add r13.xyzw, r13.xyzw, r21.xyzw
    mul r21.xyzw, r17.wwww, cb0[3].xyzw
    add r13.xyzw, r13.xyzw, r21.xyzw
    mul r21.xyzw, r15.xxxx, cb0[0].xyzw
    mul r22.xyzw, r16.xxxx, cb0[1].xyzw
    add r21.xyzw, r21.xyzw, r22.xyzw
    mul r22.xyzw, r17.xxxx, cb0[2].xyzw
    add r21.xyzw, r21.xyzw, r22.xyzw
    mul r22.xyzw, r18.xxxx, cb0[3].xyzw
    add r21.xyzw, r21.xyzw, r22.xyzw
    mul r15.xyzw, r15.yyyy, cb0[0].xyzw
    mul r16.xyzw, r16.yyyy, cb0[1].xyzw
    add r15.xyzw, r15.xyzw, r16.xyzw
    mul r16.xyzw, r17.yyyy, cb0[2].xyzw
    add r15.xyzw, r15.xyzw, r16.xyzw
    mul r16.xyzw, r18.yyyy, cb0[3].xyzw
    add r15.xyzw, r15.xyzw, r16.xyzw
    dp4 r16.y, v0.xyzw, r20.xyzw
    dp4 r16.w, v0.xyzw, r13.xyzw
    dp4 r16.z, v0.xyzw, r21.xyzw
    dp4 r16.x, v0.xyzw, r15.xyzw
    mov r12.y, r12.y
    mov r12.z, r12.z
    mov r4.zw, r16.yyyw
  else 
    ieq r10.w, r4.y, l(2)
    if_nz r10.w
      mov r13.xyz, -r1.yzwy
      add r8.yzw, r8.yyzw, r13.xxyz
      dp3 r10.w, r8.yzwy, r8.yzwy
      rsq r13.x, r10.w
      mul r19.yzw, r8.yyzw, r13.xxxx
      sqrt r8.y, r10.w
      mov r8.z, -r8.y
      max r8.y, r8.z, r8.y
      add r1.x, r1.x, l(1.000000)
      mul r8.x, r8.y, r8.x
      add r1.x, r1.x, r8.x
      max r8.x, r8.y, l(1.000000)
      mul r8.x, r8.x, r8.x
      mul r8.x, r8.x, l(1.000000)
      mul r8.x, r8.x, r10.y
      add r1.x, r1.x, r8.x
      div r19.x, l(1.000000), r1.x
    else 
      mov r19.yzw, r11.xxyz
      mov r19.x, l(1.000000)
    endif 
    mov r11.xyzw, l(0,0,0,0)
    mov r12.yzw, l(0,0,0,0)
    mov r4.zw, l(0,0,0,0)
    mov r16.xz, l(0,0,0,0)
  endif 
  mov r4.y, r4.y
else 
  mov r19.xyzw, l(0,0,0,0)
  mov r9.xyzw, l(0,0,0,0)
  mov r11.xyzw, l(0,0,0,0)
  mov r12.xyzw, l(0,0,0,0)
  mov r4.xyzw, l(0,0,0,0)
  mov r16.xz, l(0,0,0,0)
endif 
ult r1.x, l(2), cb0[17].x
if_nz r1.x
  mov r8.y, cb0[16].z
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r13.y, r8.y, l(0), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r13.z, r8.y, l(4), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r13.w, r8.y, l(8), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r8.x, r8.y, l(12), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r15.x, r8.y, l(16), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r15.y, r8.y, l(20), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r15.z, r8.y, l(24), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r15.w, r8.y, l(28), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r17.x, r8.y, l(32), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r17.y, r8.y, l(36), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r17.z, r8.y, l(40), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r17.w, r8.y, l(44), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r18.w, r8.y, l(48), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r1.x, r8.y, l(52), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r10.y, r8.y, l(56), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r10.w, r8.y, l(60), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r13.x, r8.y, l(64), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r16.y, r8.y, l(68), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r16.w, r8.y, l(72), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r20.x, r8.y, l(76), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r20.y, r8.y, l(92), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r20.z, r8.y, l(108), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r20.w, r8.y, l(124), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r21.x, r8.y, l(80), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r21.y, r8.y, l(96), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r21.z, r8.y, l(112), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r21.w, r8.y, l(128), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r22.x, r8.y, l(84), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r22.y, r8.y, l(100), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r22.z, r8.y, l(116), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r22.w, r8.y, l(132), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r23.x, r8.y, l(88), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r23.y, r8.y, l(104), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r23.z, r8.y, l(120), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r23.w, r8.y, l(136), t10.xxxx
  ine r18.x, l(0, 0, 0, 0), r13.x
  ine r18.y, l(0, 0, 0, 0), r16.y
  ine r18.z, l(0, 0, 0, 0), r16.w
  mov r15.x, r15.x
  mov r15.y, r15.y
  mov r15.z, r15.z
  mov r15.w, r15.w
  mov r13.y, r13.y
  mov r13.z, r13.z
  mov r13.w, r13.w
  mov r17.x, r17.x
  mov r17.y, r17.y
  mov r17.z, r17.z
  mov r17.w, r17.w
  mov r18.w, r18.w
  mov r10.y, r10.y
  mov r10.w, r10.w
  mov r8.x, r8.x
  mov r1.x, r1.x
  mov r8.y, r8.y
  mov r15.xyzw, r15.xyzw
  mov r18.x, r18.x
  ieq r13.x, r8.x, l(3)
  if_nz r13.x
    mov r24.xyz, -r1.yzwy
    add r24.xyz, r13.yzwy, r24.xyzx
    dp3 r13.x, r24.xyzx, r24.xyzx
    rsq r16.y, r13.x
    mul r24.yzw, r16.yyyy, r24.xxyz
    mov r17.xyz, r17.xyzx
    mov r17.w, r17.w
    mov r18.w, r18.w
    sqrt r13.x, r13.x
    mov r16.y, -r13.x
    max r13.x, r13.x, r16.y
    add r16.y, r1.x, l(1.000000)
    mul r16.w, r10.y, r13.x
    add r16.y, r16.w, r16.y
    max r13.x, r13.x, l(1.000000)
    mul r13.x, r13.x, r13.x
    mul r13.x, r13.x, l(1.000000)
    mul r13.x, r10.w, r13.x
    add r13.x, r13.x, r16.y
    div r24.x, l(1.000000), r13.x
    mul r25.xyzw, r20.xxxx, cb0[0].xyzw
    mul r26.xyzw, r21.xxxx, cb0[1].xyzw
    add r25.xyzw, r25.xyzw, r26.xyzw
    mul r26.xyzw, r22.xxxx, cb0[2].xyzw
    add r25.xyzw, r25.xyzw, r26.xyzw
    mul r26.xyzw, r23.xxxx, cb0[3].xyzw
    add r25.xyzw, r25.xyzw, r26.xyzw
    mul r26.xyzw, r20.yyyy, cb0[0].xyzw
    mul r27.xyzw, r21.yyyy, cb0[1].xyzw
    add r26.xyzw, r26.xyzw, r27.xyzw
    mul r27.xyzw, r22.yyyy, cb0[2].xyzw
    add r26.xyzw, r26.xyzw, r27.xyzw
    mul r27.xyzw, r23.yyyy, cb0[3].xyzw
    add r26.xyzw, r26.xyzw, r27.xyzw
    mul r27.xyzw, r20.zzzz, cb0[0].xyzw
    mul r28.xyzw, r21.zzzz, cb0[1].xyzw
    add r27.xyzw, r27.xyzw, r28.xyzw
    mul r28.xyzw, r22.zzzz, cb0[2].xyzw
    add r27.xyzw, r27.xyzw, r28.xyzw
    mul r28.xyzw, r23.zzzz, cb0[3].xyzw
    add r27.xyzw, r27.xyzw, r28.xyzw
    mul r20.xyzw, r20.wwww, cb0[0].xyzw
    mul r21.xyzw, r21.wwww, cb0[1].xyzw
    add r20.xyzw, r20.xyzw, r21.xyzw
    mul r21.xyzw, r22.wwww, cb0[2].xyzw
    add r20.xyzw, r20.xyzw, r21.xyzw
    mul r21.xyzw, r23.wwww, cb0[3].xyzw
    add r20.xyzw, r20.xyzw, r21.xyzw
    dp4 r21.y, v0.xyzw, r25.xyzw
    dp4 r21.w, v0.xyzw, r26.xyzw
    dp4 r21.z, v0.xyzw, r27.xyzw
    dp4 r21.x, v0.xyzw, r20.xyzw
    mov r18.y, r18.y
    mov r18.z, r18.z
    mov r8.zw, r21.yyyw
  else 
    ieq r13.x, r8.x, l(2)
    if_nz r13.x
      mov r20.xyz, -r1.yzwy
      add r13.xyz, r13.yzwy, r20.xyzx
      dp3 r13.w, r13.xyzx, r13.xyzx
      rsq r16.y, r13.w
      mul r24.yzw, r13.xxyz, r16.yyyy
      sqrt r13.x, r13.w
      mov r13.y, -r13.x
      max r13.x, r13.y, r13.x
      add r1.x, r1.x, l(1.000000)
      mul r10.y, r10.y, r13.x
      add r1.x, r1.x, r10.y
      max r10.y, r13.x, l(1.000000)
      mul r10.y, r10.y, r10.y
      mul r10.y, r10.y, l(1.000000)
      mul r10.y, r10.y, r10.w
      add r1.x, r1.x, r10.y
      div r24.x, l(1.000000), r1.x
    else 
      mov r24.yzw, r17.xxyz
      mov r24.x, l(1.000000)
    endif 
    mov r17.xyzw, l(0,0,0,0)
    mov r18.yzw, l(0,0,0,0)
    mov r8.zw, l(0,0,0,0)
    mov r21.xz, l(0,0,0,0)
  endif 
  mov r8.x, r8.x
else 
  mov r24.xyzw, l(0,0,0,0)
  mov r15.xyzw, l(0,0,0,0)
  mov r17.xyzw, l(0,0,0,0)
  mov r18.xyzw, l(0,0,0,0)
  mov r8.xyzw, l(0,0,0,0)
  mov r21.xz, l(0,0,0,0)
endif 
ult r1.x, l(3), cb0[17].x
if_nz r1.x
  mov r13.z, cb0[16].w
  mov r1.x, r13.z
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r20.y, r1.x, l(0), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r20.z, r1.x, l(4), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r20.w, r1.x, l(8), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r13.w, r1.x, l(12), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r22.x, r1.x, l(16), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r22.y, r1.x, l(20), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r22.z, r1.x, l(24), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r22.w, r1.x, l(28), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r23.x, r1.x, l(32), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r23.y, r1.x, l(36), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r23.z, r1.x, l(40), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r10.y, r1.x, l(44), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r10.w, r1.x, l(48), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r16.y, r1.x, l(52), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r16.w, r1.x, l(56), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r20.x, r1.x, l(60), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r21.y, r1.x, l(64), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r21.w, r1.x, l(68), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r23.w, r1.x, l(72), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r25.x, r1.x, l(76), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r25.y, r1.x, l(92), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r25.z, r1.x, l(108), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r25.w, r1.x, l(124), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r26.x, r1.x, l(80), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r26.y, r1.x, l(96), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r26.z, r1.x, l(112), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r26.w, r1.x, l(128), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r27.x, r1.x, l(84), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r27.y, r1.x, l(100), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r27.z, r1.x, l(116), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r27.w, r1.x, l(132), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r28.x, r1.x, l(88), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r28.y, r1.x, l(104), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r28.z, r1.x, l(120), t10.xxxx
  ld_structured_indexable(structured_buffer, stride=140)(mixed,mixed,mixed,mixed) r1.x, r1.x, l(136), t10.xxxx
  ine r21.y, l(0, 0, 0, 0), r21.y
  ine r13.x, l(0, 0, 0, 0), r21.w
  ine r13.y, l(0, 0, 0, 0), r23.w
  mov r22.x, r22.x
  mov r22.y, r22.y
  mov r22.z, r22.z
  mov r22.w, r22.w
  mov r20.y, r20.y
  mov r20.z, r20.z
  mov r20.w, r20.w
  mov r23.x, r23.x
  mov r23.y, r23.y
  mov r23.z, r23.z
  mov r10.y, r10.y
  mov r10.w, r10.w
  mov r16.w, r16.w
  mov r20.x, r20.x
  mov r13.w, r13.w
  mov r16.y, r16.y
  mov r13.z, r13.z
  mov r22.xyzw, r22.xyzw
  mov r21.y, r21.y
  ieq r21.w, r13.w, l(3)
  if_nz r21.w
    mov r29.xyz, -r1.yzwy
    add r29.xyz, r20.yzwy, r29.xyzx
    dp3 r21.w, r29.xyzx, r29.xyzx
    rsq r23.w, r21.w
    mul r29.yzw, r23.wwww, r29.xxyz
    mov r23.xyz, r23.xyzx
    mov r10.y, r10.y
    mov r10.w, r10.w
    sqrt r21.w, r21.w
    mov r23.w, -r21.w
    max r21.w, r21.w, r23.w
    add r23.w, r16.y, l(1.000000)
    mul r28.w, r16.w, r21.w
    add r23.w, r23.w, r28.w
    max r21.w, r21.w, l(1.000000)
    mul r21.w, r21.w, r21.w
    mul r21.w, r21.w, l(1.000000)
    mul r21.w, r20.x, r21.w
    add r21.w, r21.w, r23.w
    div r29.x, l(1.000000), r21.w
    mul r30.xyzw, r25.xxxx, cb0[0].xyzw
    mul r31.xyzw, r26.xxxx, cb0[1].xyzw
    add r30.xyzw, r30.xyzw, r31.xyzw
    mul r31.xyzw, r27.xxxx, cb0[2].xyzw
    add r30.xyzw, r30.xyzw, r31.xyzw
    mul r31.xyzw, r28.xxxx, cb0[3].xyzw
    add r30.xyzw, r30.xyzw, r31.xyzw
    mul r31.xyzw, r25.yyyy, cb0[0].xyzw
    mul r32.xyzw, r26.yyyy, cb0[1].xyzw
    add r31.xyzw, r31.xyzw, r32.xyzw
    mul r32.xyzw, r27.yyyy, cb0[2].xyzw
    add r31.xyzw, r31.xyzw, r32.xyzw
    mul r32.xyzw, r28.yyyy, cb0[3].xyzw
    add r31.xyzw, r31.xyzw, r32.xyzw
    mul r32.xyzw, r25.zzzz, cb0[0].xyzw
    mul r33.xyzw, r26.zzzz, cb0[1].xyzw
    add r32.xyzw, r32.xyzw, r33.xyzw
    mul r33.xyzw, r27.zzzz, cb0[2].xyzw
    add r32.xyzw, r32.xyzw, r33.xyzw
    mul r28.xyzw, r28.zzzz, cb0[3].xyzw
    add r28.xyzw, r28.xyzw, r32.xyzw
    mul r25.xyzw, r25.wwww, cb0[0].xyzw
    mul r26.xyzw, r26.wwww, cb0[1].xyzw
    add r25.xyzw, r25.xyzw, r26.xyzw
    mul r26.xyzw, r27.wwww, cb0[2].xyzw
    add r25.xyzw, r25.xyzw, r26.xyzw
    mul r26.xyzw, r1.xxxx, cb0[3].xyzw
    add r25.xyzw, r25.xyzw, r26.xyzw
    dp4 r26.x, v0.xyzw, r30.xyzw
    dp4 r26.y, v0.xyzw, r31.xyzw
    dp4 r26.z, v0.xyzw, r28.xyzw
    dp4 r26.w, v0.xyzw, r25.xyzw
    mov r13.x, r13.x
    mov r13.y, r13.y
  else 
    ieq r1.x, r13.w, l(2)
    if_nz r1.x
      mov r1.xyz, -r1.yzwy
      add r1.xyz, r1.xyzx, r20.yzwy
      dp3 r1.w, r1.xyzx, r1.xyzx
      rsq r20.y, r1.w
      mul r29.yzw, r1.xxyz, r20.yyyy
      sqrt r1.x, r1.w
      mov r1.y, -r1.x
      max r1.x, r1.y, r1.x
      add r1.y, r16.y, l(1.000000)
      mul r1.z, r1.x, r16.w
      add r1.y, r1.z, r1.y
      max r1.x, r1.x, l(1.000000)
      mul r1.x, r1.x, r1.x
      mul r1.x, r1.x, l(1.000000)
      mul r1.x, r1.x, r20.x
      add r1.x, r1.x, r1.y
      div r29.x, l(1.000000), r1.x
    else 
      mov r29.yzw, r23.xxyz
      mov r29.x, l(1.000000)
    endif 
    mov r26.xyzw, l(0,0,0,0)
    mov r23.xyz, l(0,0,0,0)
    mov r13.xy, l(0,0,0,0)
    mov r10.y, l(0)
    mov r10.w, l(0)
  endif 
  mov r13.w, r13.w
else 
  mov r29.xy, l(0,0,0,0)
  mov r29.zw, l(0,0,0,0)
  mov r22.xyzw, l(0,0,0,0)
  mov r13.x, l(0)
  mov r13.yzw, l(0,0,0,0)
  mov r26.xyzw, l(0,0,0,0)
  mov r23.xyz, l(0,0,0,0)
  mov r10.y, l(0)
  mov r10.w, l(0)
  mov r21.y, l(0)
endif 
dp4 r1.x, r0.xyzw, cb0[4].xyzw
dp4 r1.y, r0.xyzw, cb0[5].xyzw
dp4 r1.z, r0.xyzw, cb0[6].xyzw
dp4 r1.w, r0.xyzw, cb0[7].xyzw
dp4 r0.x, r1.xyzw, cb0[12].xyzw
dp4 r0.y, r1.xyzw, cb0[13].xyzw
dp4 r0.z, r1.xyzw, cb0[14].xyzw
dp4 r0.w, r1.xyzw, cb0[15].xyzw
dp3 r1.x, v1.xyzx, cb0[0].xyzx
dp3 r1.y, v1.xyzx, cb0[1].xyzx
dp3 r1.z, v1.xyzx, cb0[2].xyzx
dp3 r1.w, r1.xyzx, r1.xyzx
rsq r1.w, r1.w
mul r1.xyz, r1.wwww, r1.xyzx
dp3 r20.x, v3.xyzx, cb0[0].xyzx
dp3 r20.y, v3.xyzx, cb0[1].xyzx
dp3 r20.z, v3.xyzx, cb0[2].xyzx
dp3 r1.w, r20.xyzx, r20.xyzx
rsq r1.w, r1.w
mul r20.xyz, r1.wwww, r20.xyzx
dp3 r25.x, v4.xyzx, cb0[0].xyzx
dp3 r25.y, v4.xyzx, cb0[1].xyzx
dp3 r25.z, v4.xyzx, cb0[2].xyzx
dp3 r1.w, r25.xyzx, r25.xyzx
rsq r1.w, r1.w
mul r25.xyz, r1.wwww, r25.xyzx
mov r16.yw, v2.xxxy
dp4 r27.x, l(0.000000, 0.000000, 0.000000, 1.000000), cb0[8].xyzw
dp4 r27.y, l(0.000000, 0.000000, 0.000000, 1.000000), cb0[9].xyzw
dp4 r27.z, l(0.000000, 0.000000, 0.000000, 1.000000), cb0[10].xyzw
mov r1.w, cb0[17].x
mov o0.xyzw, r0.xyzw
mov o1.xyz, r1.xyzx
mov o1.w, r7.w
mov o2.xyz, r20.xyzx
mov o2.w, r11.w
mov o3.xyz, r25.xyzx
mov o3.w, r12.w
mov o4.xy, r16.ywyy
mov o4.z, r6.w
mov o4.w, r17.w
mov o5.xyz, r27.xyzx
mov o5.w, r18.w
mov o6.xyzw, r2.xyzw
mov o7.x, r14.x
mov o7.y, r14.y
mov o7.z, r14.z
mov o7.w, r14.w
mov o8.x, r5.x
mov o8.y, r5.y
mov o8.z, r5.z
mov o8.w, r5.w
mov o9.x, r6.x
mov o9.y, r6.y
mov o9.z, r6.z
mov o9.w, r10.y
mov o10.x, r7.x
mov o10.y, r7.y
mov o10.z, r7.z
mov o10.w, r3.w
mov o11.x, r3.x
mov o11.y, r12.x
mov o11.z, r12.y
mov o11.w, r12.z
mov o12.x, r3.y
mov o12.y, r3.z
mov o12.z, r10.z
mov o12.w, r10.x
mov o13.x, r19.x
mov o13.y, r19.y
mov o13.z, r19.z
mov o13.w, r19.w
mov o14.x, r9.x
mov o14.y, r9.y
mov o14.z, r9.z
mov o14.w, r9.w
mov o15.x, r11.x
mov o15.y, r11.y
mov o15.z, r11.z
mov o15.w, r10.w
mov o16.x, r4.x
mov o16.y, r4.y
mov o16.z, r18.x
mov o16.w, r18.y
mov o17.x, r4.z
mov o17.y, r4.w
mov o17.z, r16.z
mov o17.w, r16.x
mov o18.x, r24.x
mov o18.y, r24.y
mov o18.z, r24.z
mov o18.w, r24.w
mov o19.x, r15.x
mov o19.y, r15.y
mov o19.z, r15.z
mov o19.w, r15.w
mov o21.x, r18.z
mov o21.y, r8.y
mov o21.z, r8.x
mov o21.w, r21.y
mov o22.x, r8.z
mov o22.y, r8.w
mov o22.z, r21.z
mov o22.w, r21.x
mov o23.xyzw, r29.xyzw
mov o24.xyzw, r22.xyzw
mov o26.xyzw, r13.xyzw
mov o27.xyzw, r26.xyzw
mov o20.x, r17.x
mov o20.y, r17.y
mov o20.z, r17.z
mov o25.xyz, r23.xyzx
mov o28.x, r1.w
ret 
// Approximately 747 instruction slots used