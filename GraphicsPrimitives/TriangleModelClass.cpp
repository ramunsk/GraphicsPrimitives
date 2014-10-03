////////////////////////////////////////////////////////////////////////////////
// Filename: triangle_modelclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "trianglemodelclass.h"


TriangleModelClass::TriangleModelClass() :IndexModelClass()
{
}


TriangleModelClass::TriangleModelClass(const TriangleModelClass& other)
{
}


TriangleModelClass::~TriangleModelClass()
{
}


bool TriangleModelClass::InitializeBuffers(ID3D11Device* device)
{
	HRESULT result;
	//
	// Process the vertex buffer
	//
	VertexType* vertices;
	D3D11_BUFFER_DESC vertexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData;

	// Set the number of vertices in the vertex array.
	int vCount = 5;
	SetVertexCount(vCount);

	// Create the vertex array.
	vertices = new VertexType[vCount];
	if (!vertices)
	{
		return false;
	}

	// Load the vertex array with data.
	vertices[0].position = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);  // Bottom front left
	vertices[0].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);

	vertices[1].position = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);  // Bottom back left
	vertices[1].color = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);

	vertices[2].position = D3DXVECTOR3(1.0f, -1.0f, -1.0f);  // Bottom back right
	vertices[2].color = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);

	vertices[3].position = D3DXVECTOR3(1.0f, -1.0f, 1.0f);  // Bottom front right
	vertices[3].color = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);

	vertices[4].position = D3DXVECTOR3(0.0f, 2.0f, 0.0f);  // Top middle
	vertices[4].color = D3DXVECTOR4(0.0f, 1.0f, 01.0f, 1.0f);


	// Set up the description of the static vertex buffer.
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * vCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	ZeroMemory(&vertexData, sizeof(vertexData));
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Release the array now that the vertex buffer has been created and loaded.
	delete[] vertices;
	vertices = 0;

	//
	// Process the index buffer	
	//
	unsigned long* indices;
	D3D11_BUFFER_DESC indexBufferDesc;
	D3D11_SUBRESOURCE_DATA indexData;

	// Set the number of indices in the index array.
	int iCount = 18;
	SetIndexCount(iCount);

	// Create the index array.
	indices = new unsigned long[iCount];
	if (!indices)
	{
		return false;
	}
	// Load the index array with data.
	indices[0] = 0;
	indices[1] = 4;
	indices[2] = 1;

	indices[3] = 1;
	indices[4] = 4;
	indices[5] = 2;

	indices[6] = 2;
	indices[7] = 4;
	indices[8] = 3;

	indices[9] = 3;
	indices[10] = 4;
	indices[11] = 0;

	indices[12] = 0;
	indices[13] = 1;
	indices[14] = 2;

	indices[15] = 2;
	indices[16] = 3;
	indices[17] = 0;

	// Set up the description of the static index buffer.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * iCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// Release the array now that the vertex buffer has been created and loaded.
	delete[] indices;
	indices = 0;

	return true;
}


void TriangleModelClass::Render(ID3D11DeviceContext* deviceContext)
{
	//Update the world transformations
	UINT  iTime = timeGetTime() % 2000;
	float fAngle = iTime * 2 * D3DX_PI / 2000.0f;
	D3DXMATRIX rotMatrix;
	D3DXMatrixRotationY(&rotMatrix, fAngle);
	//D3DXMatrixRotationAxis(&rotMatrix, 1.0f, 1.0f,1.0f, fAngle );
	SetModelWorldMatrix(rotMatrix);
	//SetModelWorldMatrix(XMMatrixIdentity());

	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(deviceContext);

	return;
}


void TriangleModelClass::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;

	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType);
	offset = 0;

	// Set the vertex buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

	// Set the index buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// render primitives
	deviceContext->DrawIndexed(GetIndexCount(), 0, 0);

	return;
}