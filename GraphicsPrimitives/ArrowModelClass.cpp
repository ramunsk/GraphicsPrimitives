#include "ArrowModelClass.h"

ArrowModelClass::ArrowModelClass() :IndexModelClass()
{
}

ArrowModelClass::~ArrowModelClass()
{
}

bool ArrowModelClass::InitializeBuffers(ID3D11Device* device)
{
	HRESULT result;

	D3DXVECTOR4 COLOR_WHITE =      { 1.0f, 1.0f, 1.0f, 1.0f };
	D3DXVECTOR4 COLOR_LIGHT_GRAY = { 0.9f, 0.9f, 0.9f, 1.0f };

	VertexType* vertices = new VertexType[]
	{
		{-378.0f,   0.0f, 378.0f, COLOR_WHITE},       // 0
		{-343.0f, -15.0f, 343.0f, COLOR_LIGHT_GRAY},  // 1
		{-342.0f,  -2.0f, 344.0f, COLOR_LIGHT_GRAY}   // 2
	};

	int vertexCount = sizeof(vertices) / sizeof(vertices[0]);
	SetVertexCount(vertexCount);

	D3D11_BUFFER_DESC vertexBufferDesc;
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA vertexData;
	ZeroMemory(&vertexData, sizeof(vertexData));
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	delete[] vertices;
	vertices = 0;

	unsigned long* indices;
	D3D11_BUFFER_DESC indexBufferDesc;
	D3D11_SUBRESOURCE_DATA indexData;

	// Set the number of indices in the index array.
	int iCount = 3;
	SetIndexCount(iCount);

	// Create the index array.
	indices = new unsigned long[iCount];
	if (!indices)
	{
		return false;
	}
	// Load the index array with data.
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;

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

void ArrowModelClass::RenderBuffers(ID3D11DeviceContext* deviceContext)
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

void ArrowModelClass::Render(ID3D11DeviceContext* deviceContext)
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