#pragma once 

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10math.h>

#include "IndexModelClass.h"

class ArrowModelClass : public IndexModelClass
{
public:
	ArrowModelClass();
	~ArrowModelClass();

	void Render(ID3D11DeviceContext*);

private:
	bool InitializeBuffers(ID3D11Device*);
	void RenderBuffers(ID3D11DeviceContext*);

    D3DXMATRIX _staticRotation;
    D3DXMATRIX _staticScale;
   
};
