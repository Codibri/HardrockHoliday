
//--------------------------------------------------------------------------------------
// Copyright (c) Tobias Breiner
//--------------------------------------------------------------------------------------

SamplerState linearSampler : register(s0);


cbuffer ObjectInfo : register( b2 )
{
	matrix mWorldViewProjection;
}


//--------------------------------------------------------------------------------------
// Postprozessinformationen: 
//--------------------------------------------------------------------------------------
cbuffer TexInfo : register( b3 )
{
	float4 f4ColorEffect;
	float fParam1; 
	float fParam2; 
	float fBlurStrength; 
	float frCameraFocusDist; 
	bool abTexFlag[16]; 
   	// 0 = Blur,		1 = MotionBlur,		 2 = DistanceBlur,		 3 = Bump
	// 4 = LightGlow,	5 = HightligtGlow,	 6 = Filmtex,			 7 = 
	// 8 = GodRays,		9 = GlowWhite,		10 = ,					11 = 
	//12 = RedStereo   13 = GreenBlueStereo	14 = 

}


//--------------------------------------------------------------------------------------
// Textur Buffer
//--------------------------------------------------------------------------------------

Texture2D tex2D[4] : register ( t12 ); // texture

//--------------------------------------------------------------------------------------

/*
struct VS_INPUT_POST
{
    float4 f4Pos : POSITION;
    float2 f2TexCoord : TEXCOORD; 
};
*/
struct VS_INPUT_POST
{
    float4 f4Pos : POSITION;
    float3 f3Normal : NORMAL;
    float2 f2TexCoord : TEXCOORD; 
    float3 f3Tangent : TANGENT;
    float3 f3Bitangent : BITANGENT;
};


struct PS_INPUT_POST
{
   float4 f4Pos : SV_POSITION0;
   float2 f2TexCoord : TEXCOORD0;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
PS_INPUT_POST VS_POST( VS_INPUT_POST input )
{
	
    PS_INPUT_POST output = (PS_INPUT_POST)0;

	output.f4Pos = mul(output.f4Pos, mWorldViewProjection);
	output.f2TexCoord = input.f2TexCoord;
    return output;
}


//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS_POST( PS_INPUT_POST input) : SV_Target0
{
	

	float4 f4ColorOut = tex2D[0].Sample(linearSampler, input.f2TexCoord);

	if(abTexFlag[0]) // Glow
	{
	}
	f4ColorOut.r = 100.111f;
	f4ColorOut.b = 0;
    return f4ColorOut ;
}











