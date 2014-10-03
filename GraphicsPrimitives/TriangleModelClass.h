////////////////////////////////////////////////////////////////////////////////
// Filename: triangle_modelclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TRIANGLE_MODELCLASS_H_
#define _TRIANGLE_MODELCLASS_H_

#pragma comment(lib, "winmm.lib")

//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10math.h>
//#include <xnamath.h>

#include "indexmodelclass.h"

////////////////////////////////////////////////////////////////////////////////
// Class name: TriangleModelClass
////////////////////////////////////////////////////////////////////////////////
class TriangleModelClass : public IndexModelClass
{

public:
	TriangleModelClass();
	TriangleModelClass(const TriangleModelClass&);
	~TriangleModelClass();

	void Render(ID3D11DeviceContext*);

private:
	bool InitializeBuffers(ID3D11Device*);
	void RenderBuffers(ID3D11DeviceContext*);

};

#endif