//------------------------------------------------------------------
// CDXUtilities: This class contains helpful functions for DirectX development.
//
// Autor: Michael Ruecker
//-------------------------------------------------------------------

#pragma once
#include "DirectX.h"
namespace Vektoria
{

class CDXUtilities
{
public:
	CDXUtilities(CDirectX *renderAPI);
	~CDXUtilities(void);
	HRESULT CreateBuffer( UINT uElementSize, UINT uCount, VOID * pInitData, ID3D11Buffer ** pBufOut, UINT uiBindFlags, UINT uiMiscFlags, D3D11_USAGE Usage = D3D11_USAGE_DEFAULT, UINT uiCPUAccessFlags = 0 );
	void TransferFromGPU(ID3D11Resource * pResource, int iSubresource, BYTE * pBuffer, int iSize);
	HRESULT CreateBufferUAV(ID3D11Buffer * pBuffer, ID3D11UnorderedAccessView ** pUAVOut, bool bAppendBuffer, bool bCounterIfNotAppend);
	HRESULT CreateBufferSRV(ID3D11Buffer * pBuffer, ID3D11ShaderResourceView ** pSRVOut);
	void RunComputeShaderIndirect( int iCS, ID3D11UnorderedAccessView ** aUAVs, int iUAVs, ID3D11ShaderResourceView ** aSRVs, int iSRVs, ID3D11Buffer * pbThreadGroups, UINT uiAlignedOffsetForArgs, UINT *piUAVElementCounts = 0 );
private:
	CDirectX *m_pRenderAPI;
};

}