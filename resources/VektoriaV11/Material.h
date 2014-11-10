#pragma once
#include "Textures.h"
#include "Color.h"
#include <string>

#include "DistributedGlobal.h"


//---------------------------------------------------
// CMaterial: Klasse für Materialien
//
// Autoren: Prof. Dr. Tobias Breiner
// Letzte Änderung: 2011-08-07
//---------------------------------------------------



//  0 = Image,		 4 = Glow,			 8 = Specular,			12 = Bump
// 16 = ImageBlack,	20 = GlowAsImgae,	24 = SpecularAsImage,	28 =HeightAsImage
// 32 = ImageWhite,	36 = GlowWhite,		40 = SpecularWhite,		44 =Height
// 48 = ShadingOff, 52 = Environment,	56 = POM


#define TEXFLAG_NOIMAGE 0
#define TEXFLAG_IMAGE 1
#define TEXFLAG_IMAGEBLACK 2
#define TEXFLAG_IMAGEWHITE 3
#define TEXFLAG_IMAGEPure 4

#define TEXFLAG_NOGLOW 0
#define TEXFLAG_GLOW 1
#define TEXFLAG_GLOWASIMAGE 2
#define TEXFLAG_GLOWWHITE 3
#define TEXFLAG_GLOWASAMBIENT 5

#define TEXFLAG_NOSPECULAR 0
#define TEXFLAG_SPECULAR 1
#define TEXFLAG_SPECULARASIMAGE 2
#define TEXFLAG_SPECULARWHITE 3

#define TEXFLAG_NOBUMP 0
#define TEXFLAG_BUMP 1
#define TEXFLAG_HEIGHTASIMAGE 2
#define TEXFLAG_HEIGHT 3

#define TEXFLAG_NOENVIRONMENTAL 0;
#define TEXFLAG_ENVIRONMENTAL 1;

#define TEXFLAG_NOTEXBRDF 0;
#define TEXFLAG_TEXBRDF 1;

#define TEXFLAG_NOPOM 0;
#define TEXFLAG_POM	  1;

#define TEXFLAG_NOTHICKNESS 0;
#define TEXFLAG_THICKNESS	1;

namespace Vektoria
{

class CGeos;

enum ETextureAddressMode
{
	eTextureAdressMode_Wrap,
	eTextureAdressMode_Mirror,
	eTextureAdressMode_Clamp
};

class CHardware;

class CMaterial
{
	friend class CMaterials;
private:
	void Tick(float & fTimeDelta, CHardware & zh);
public:
	CMaterial();
	~CMaterial();
	CMaterial operator=(CMaterial & material);
	void Copy(CMaterial & material);

	void Init();
	void Init(CColor colorDiffuse, CColor colorAmbient, CColor colorSpecular);
	void Fini();

	void SetTextureSky(CTexture *ptexture); // Setzt eine Textur, die für Skymaps, Skydomes etc. geeignet ist  
	void SetTextureImage(CTexture *ptexture);
	void SetTextureGlow(CTexture *ptexture);
	void SetTextureSpecular(CTexture *ptexture);
	void SetTextureBump(CTexture *ptexture);
	void SetTextureHeight(CTexture *ptexture);
	void SetTextureEnvironment(CTexture *ptexture);
	void SetTextureThickness(CTexture* ptexture);
	void SetTextureSprite(CTexture *ptexture);	// Setzt eine Textur, die für Sprites wie Backgrounds, Overlays, Writings und WritingChars geeignet ist   

	CImage * MakeTextureImage(char * acPath);
	CImage * MakeTextureGlow(char * acPath);
	CImage * MakeTextureSpecular(char * acPath);
	CImage * MakeTextureBump(char * acPath);
	CImage * MakeTextureHeight(char * acPath); //== Parallax Occlusion Mapping mit Heightmap
	CImage * MakeTextureEnvironment(char * acPath);
	CImage * MakeTextureSky(char * acPath); // Erzeugt eine Texturhierarchie, die für Skymaps, Skydomes etc. geeignet ist  
	CImage * MakeTextureThickness(char * acPath, CColor colorSSS); // Materialdickebeschreibung für Subsurfacescattering und Farbe des Subsurfaces
	CImage * MakeTextureSprite(char * acPath); // Erzeugt eine Texturhierarchie, die für Sprites wie Backgrounds, Overlays, Writings und WritingChars geeignet ist   

	void SetAni(int ixPics, int iyPics, float fFps); // Erzeugt ein animiertes Material 
	void SetBot(int ixPics, int iyPics); // Erzeugt ein steuerbares Material
	void SetPic(int ixPic, int iyPic); // Setzt Unterbild bei animierten oder steuerbaren Materialien

	void SetShadingOn();
	void SetShadingOff();
	void SetTextureGlowWhite();
	void SetTextureGlowBlack();
	void SetTextureGlowAsImage();
	void SetTextureGlowAsAmbient();
	void SetTextureSpecularWhite();
	void SetTextureSpecularBlack();
	void SetTextureSpecularAsImage();
	void SetTextureTexBRDF(); //Texturbasiertes BRDF mit Normal- und Heightmap. Benötigt POM und Bumpmapping 

	void SetColorAmbient(CColor color);
	void SetBumpStrength(float fBumpStrength);
	void SetSpecularSharpness(float fSpecularSharpness);
	void SetDiffuseSharpness(float fDiffuseSharpness);
	void SetTransparency(float frTransparancy);
	void SetAbsoluteMaterialThickness(float fThickness); // Absolute Materialdicke für Subsurfacescattering
	void SetRimLightStrength(float fRimStrength); // Stärke der Glanzlichter des Subsurfacescattering
	void SetBRDFReflectance(float fReflectance); // Stärke der Reflektionen des BRDF
	void SetEnviromentMapIntensityReduction(float fIntensity); //Stärke der Enviromentmap verringern
	void SetSubSurfaceColor(CColor color);

	void SetTransparencyOn();
	void SetTransparencyOff();

	void SetChromaKeyingOn();
	void SetChromaKeyingOff();

	void SetTextureAddressMode(ETextureAddressMode eTextureAddressMode);

	CTexture * m_ptextureImage; 
	CTexture * m_ptextureGlow; 
	CTexture * m_ptextureSpecular; 
	CTexture * m_ptextureBump;
	CTexture * m_ptextureEnvironment;
    CTexture * m_ptexturePOM;
	CTexture * m_ptextureThickness;

	CColor m_colorDiffuse;
	CColor m_colorAmbient;
	CColor m_colorSpecular;
	CColor m_colorSSS;

	float m_fDiffuseSharpness;
	float m_fSpecularSharpness;
	float m_fBumpStrength;
	float m_frTransparency;
	float m_fAbsoluteThickness;
	float m_fBRDFReflectance;
	float m_fRimLightStr;
	float m_fEnviromentInt;

	int m_iFlagsImage;
	int m_iFlagsGlow;
	int m_iFlagsSpecular;
	int m_iFlagsBump;
	int m_iFlagsEnvironment;
	int m_iFlagsPOM;
	int m_iFlagsTexBRDF;
	int m_iFlagsSSS;

	bool m_bShading;
	bool m_bTransparent;
	bool m_bChromaKey;
	int m_id;
	bool m_bChanged;
	bool m_bChangedAni;

	CGeos * m_pgeos; // Liste aller Geometrien, die das Material verwenden

	// Animierte Materialien:

	bool m_bAni;
	bool m_bBot;
	int m_ixPics;
	int m_iyPics;

	int m_ixPic;
	int m_iyPic;

	int m_iPic;
	int m_iPics;
	float m_fPic;
	float m_fFps;

	ETextureAddressMode m_eTextureAddressMode;

#ifdef NETWORKMASTER
	unsigned int GetidId();
	
private:

	unsigned int m_idId;
	int m_icId;
#endif
};

}