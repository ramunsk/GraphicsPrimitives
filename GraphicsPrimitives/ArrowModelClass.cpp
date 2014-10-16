#include "ArrowModelClass.h"
#include <vector>

ArrowModelClass::ArrowModelClass() :IndexModelClass()
{
}

ArrowModelClass::~ArrowModelClass()
{
}

bool ArrowModelClass::InitializeBuffers(ID3D11Device* device)
{
	HRESULT result;

	///
	/// VERTICES
	///
	D3DXVECTOR4 COLOR_WHITE =       { 1.00f, 1.00f, 1.00f, 1.0f };
	D3DXVECTOR4 COLOR_LIGHT_GRAY =  { 0.60f, 0.60f, 0.60f, 1.0f };
	D3DXVECTOR4 COLOR_BLUE =        { 0.15f, 0.02f, 0.94f, 1.0f };
	D3DXVECTOR4 COLOR_LIGHT_BROWN = { 0.71f, 0.31f, 0.04f, 1.0f };
	D3DXVECTOR4 COLOR_DARK_BROWN = { 0.68f, 0.30f, 0.01f, 1.0f };
	D3DXVECTOR4 COLOR_RED = { 0.4f, 0.0f, 0.00f, 1.0f };
	D3DXVECTOR4 COLOR_ORANGE = { 1.0f, 0.4f, 0.00f, 1.0f };
	

	std::vector<VertexType> vertices = {
		// Antgalis
		{ -378.0f, 378.0f, 0.0f, COLOR_WHITE },       // 0
		{ -343.0f, 343.0f, -15.0f, COLOR_LIGHT_GRAY },	// 1
		{ -342.0f, 344.0f, -2.0f, COLOR_LIGHT_GRAY },	// 2
		{ -332.0f, 354.0f, -0.0f, COLOR_LIGHT_GRAY },	// 3
		{ -341.0f, 344.0f, 2.0f, COLOR_LIGHT_GRAY },	// 4
		{ -343.0f, 343.0f, 15.0f, COLOR_LIGHT_GRAY },	// 5
		{ -344.0f, 342.0f, 2.0f, COLOR_LIGHT_GRAY },	// 6
		{ -354.0f, 332.0f, 0.0f, COLOR_LIGHT_GRAY },	// 7
		{ -344.0f, 341.0f, -2.0f, COLOR_LIGHT_GRAY },	// 8
		// Laikiklis
		{ -343.0f, 343.0f, -6.0f, COLOR_BLUE }, // 9
		{ -329.0f, 329.0f, -6.0f, COLOR_BLUE },	// 10
		{ -340.0f, 346.0f, -4.0f, COLOR_BLUE },	// 11
		{ -326.0f, 332.0f, -4.0f, COLOR_BLUE },	// 12
		{ -339.0f, 347.0f, 0.0f, COLOR_BLUE },	// 13
		{ -325.0f, 333.0f, 0.0f, COLOR_BLUE },	// 14
		{ -340.0f, 346.0f, 4.0f, COLOR_BLUE },	// 15
		{ -326.0f, 332.0f, 4.0f, COLOR_BLUE },	// 16
		{ -343.0f, 343.0f, 6.0f, COLOR_BLUE },	// 17
		{ -329.0f, 329.0f, 6.0f, COLOR_BLUE },	// 18
		{ -346.0f, 340.0f, 4.0f, COLOR_BLUE },	// 19
		{ -332.0f, 326.0f, 4.0f, COLOR_BLUE },	// 20
		{ -347.0f, 339.0f, 0.0f, COLOR_BLUE },	// 21
		{ -333.0f, 325.0f, 0.0f, COLOR_BLUE },	// 22
		{ -346.0f, 340.0f, -4.0f, COLOR_BLUE },	// 23
		{ -332.0f, 326.0f, -4.0f, COLOR_BLUE },	// 24
		// Kotas
		{ -329.0f, 329.0f, -5.0f, COLOR_LIGHT_BROWN }, // 25
		{ 378.0f, -378.0f, -5.0f, COLOR_DARK_BROWN }, // 26
		{ -326.0f, 331.0f, -4.0f, COLOR_LIGHT_BROWN }, // 27
		{ 381.0f, -376.0f, -4.0f, COLOR_DARK_BROWN }, // 28
		{ -325.0f, 332.0f, 0.0f, COLOR_LIGHT_BROWN }, // 29
		{ 382.0f, -375.0f, 0.0f, COLOR_DARK_BROWN }, // 30
		{ -326.0f, 331.0f, 4.0f, COLOR_LIGHT_BROWN }, // 31
		{ 381.0f, -376.0f, 4.0f, COLOR_DARK_BROWN }, // 32
		{ -329.0f, 329.0f, 5.0f, COLOR_LIGHT_BROWN }, // 33
		{ 378.0f, -378.0f, 5.0f, COLOR_DARK_BROWN }, // 34
		{ -331.0f, 326.0f, 4.0f, COLOR_LIGHT_BROWN }, // 35
		{ 376.0f, -381.0f, 4.0f, COLOR_DARK_BROWN }, // 36
		{ -332.0f, 325.0f, 0.0f, COLOR_LIGHT_BROWN }, // 37
		{ 375.0f, -382.0f, 0.0f, COLOR_DARK_BROWN }, // 38
		{ -331.0f, 326.0f, -4.0f, COLOR_LIGHT_BROWN }, // 39
		{ 376.0f, -381.0f, -4.0f, COLOR_DARK_BROWN }, // 40
		// Plunksnos 1
		{ 273.0f, -271.0f, -4.0f, COLOR_RED },    // 41
		{ 291.0f, -289.0f, -5.0f, COLOR_RED },    // 42 
		{ 292.0f, -288.0f, -4.0f, COLOR_RED },    // 43
		{ 302.0f, -292.0f, -18.0f, COLOR_ORANGE }, // 44
		{ 291.0f, -289.0f, -4.0f, COLOR_RED }, // 45
		{ 308.0f, -307.0f, -5.0f, COLOR_RED }, // 46
		{ 310.0f, -306.0f, -4.0f, COLOR_RED }, // 47
		{ 320.0f, -309.0f, -18.0f, COLOR_ORANGE }, // 48
		{ 309.0f, -306.0f, -4.0f, COLOR_RED }, // 49
		{ 326.0f, -325.0f, -5.0f, COLOR_RED }, // 50
		{ 327.0f, -323.0f, -4.0f, COLOR_RED }, // 51
		{ 338.0f, -327.0f, -18.0f, COLOR_ORANGE }, // 52
		{ 327.0f, -324.0f, -4.0f, COLOR_RED }, // 53
		{ 344.0f, -342.0f, -5.0f, COLOR_RED }, // 54
		{ 345.0f, -341.0f, -4.0f, COLOR_RED }, // 55
		{ 355.0f, -345.0f, -18.0f, COLOR_ORANGE }, // 56
		// Plunksnos 2
        { 275.0f, -269.0f, 2.0f, COLOR_RED }, // 57
        { 293.0f, -287.0f, 1.0f, COLOR_RED }, // 58
        { 293.0f, -287.0f, 3.0f, COLOR_RED }, // 59
        { 310.0f, -284.0f, 8.0f, COLOR_ORANGE }, // 60
        { 293.0f, -287.0f, 2.0f, COLOR_RED }, // 61
        { 311.0f, -304.0f, 1.0f, COLOR_RED }, // 62
        { 310.0f, -305.0f, 3.0f, COLOR_RED }, // 63
        { 327.0f, -302.0f, 8.0f, COLOR_ORANGE }, // 64
        { 311.0f, -305.0f, 2.0f, COLOR_RED }, // 65
        { 329.0f, -322.0f, 1.0f, COLOR_RED }, // 66
        { 328.0f, -323.0f, 3.0f, COLOR_RED }, // 67
        { 345.0f, -320.0f, 8.0f, COLOR_ORANGE }, // 68
        { 328.0f, -322.0f, 2.0f, COLOR_RED }, // 69
        { 346.0f, -340.0f, 1.0f, COLOR_RED }, // 70
        { 346.0f, -340.0f, 3.0f, COLOR_RED }, // 71
        { 363.0f, -337.0f, 8.0f, COLOR_ORANGE }, // 72
        // Plunksnos 3
        { 271.0f, -274.0f,  4.0f, COLOR_RED }, // 73
        { 289.0f, -291.0f,  5.0f, COLOR_RED }, // 74
        { 288.0f, -292.0f,  4.0f, COLOR_RED }, // 75 
        { 292.0f, -302.0f, 18.0f, COLOR_ORANGE }, // 76
        { 289.0f, -291.0f,  4.0f, COLOR_RED }, // 77
        { 307.0f, -308.0f,  5.0f, COLOR_RED }, // 78
        { 306.0f, -310.0f,  4.0f, COLOR_RED }, // 79
        { 309.0f, -320.0f, 18.0f, COLOR_ORANGE }, // 80
        { 306.0f, -309.0f,  4.0f, COLOR_RED }, // 81
        { 325.0f, -326.0f,  5.0f, COLOR_RED }, // 82
        { 323.0f, -327.0f,  4.0f, COLOR_RED }, // 83
        { 327.0f, -338.0f, 18.0f, COLOR_ORANGE }, // 84
        { 324.0f, -327.0f,  4.0f, COLOR_RED }, // 85
        { 342.0f, -344.0f,  5.0f, COLOR_RED }, // 86
        { 341.0f, -345.0f,  4.0f, COLOR_RED }, // 87
        { 345.0f, -355.0f, 18.0f, COLOR_ORANGE }, // 88
        // Plunksnos 4
        { 269.0f, -275.0f, -2.0f, COLOR_RED }, // 89
        { 287.0f, -293.0f, -1.0f, COLOR_RED }, // 90
        { 287.0f, -293.0f, -3.0f, COLOR_RED }, // 91
        { 284.0f, -310.0f, -8.0f, COLOR_ORANGE }, // 92
        { 287.0f, -293.0f, -2.0f, COLOR_RED }, // 93
        { 304.0f, -311.0f, -1.0f, COLOR_RED }, // 94
        { 305.0f, -310.0f, -3.0f, COLOR_RED }, // 95
        { 302.0f, -327.0f, -8.0f, COLOR_ORANGE }, // 96
        { 305.0f, -311.0f, -2.0f, COLOR_RED }, // 97
        { 322.0f, -329.0f, -1.0f, COLOR_RED }, // 98
        { 323.0f, -328.0f, -3.0f, COLOR_RED }, // 99
        { 320.0f, -345.0f, -8.0f, COLOR_ORANGE }, // 100
        { 322.0f, -328.0f, -2.0f, COLOR_RED }, // 101
        { 340.0f, -346.0f, -1.0f, COLOR_RED }, // 102
        { 340.0f, -346.0f, -3.0f, COLOR_RED }, // 103
        { 337.0f, -363.0f, -8.0f, COLOR_ORANGE }, // 104




	};

	int vertexCount = vertices.size();
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
	vertexData.pSysMem = &vertices[0];
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	///
	/// INDICES
	///
	std::vector<unsigned long> indices = {
		// Antaglis
		0, 1, 2,
		0, 2, 3,
		0, 3, 4,
		0, 4, 5,
		0, 5, 6,
		0, 6, 7, 
		0, 7, 8,
		0, 8, 1,
		1, 8, 2,
		3, 2, 4,
		5, 4, 6,
		7, 6, 8,
		4, 8, 6,
		4, 2, 8,
		// Laikiklis
		 9, 10, 11,
		11, 10, 12,
		11, 12, 13,
		13, 12, 14,
		13, 14, 15,
		15, 14, 16,
		15, 16, 17,
		17, 16, 18,
		17, 18, 19,
		19, 18, 20,
		19, 20, 21,
		21, 20, 22,
		21, 22, 23,
		23, 22, 24,
		23, 24,  9,
		 9, 24, 10,
		 9, 11, 13, //
		13, 15, 17,
		17, 19, 21,
		21, 23,  9,
		 9, 13, 17,
		 9, 17, 21,
		10, 14, 12,
		14, 18, 16,
		18, 22, 20,
		22, 10, 24,
		10, 22, 18,
		10, 18, 14,
		// Kotas
		25, 26, 27,
		27, 26, 28,
		27, 28, 29,
		29, 28, 30,
		29, 30, 31,
		31, 30, 32,
		31, 32, 33,
		33, 32, 34,
		33, 34, 35,
		35, 34, 36,
		35, 36, 37,
		37, 36, 38,
		37, 38, 39,
		39, 38, 40,
		39, 40, 25,
		25, 40, 26,
		25, 27, 29, //
		29, 31, 33,
		33, 35, 37, 
		37, 39, 25,
		25, 29, 33,
		25, 33, 37,
		26, 30, 28, //
		30, 34, 32, 
		34, 38, 36, 
		38, 26, 40,
		26, 38, 34, 
		26, 34, 30,
		// Plunksnos 1
		41, 43, 42,
		42, 43, 44,
		41, 44, 43,
		41, 42, 44,
		45, 47, 46, //
		46, 47, 48,
		45, 48, 47,
		45, 46, 48,
		49, 51, 50, //
		50, 51, 52,
		49, 52, 51,
		49, 50, 52,
		53, 55, 54, //
		54, 55, 56,
		53, 56, 55,
		53, 54, 56,
		// Plunksnos 2
		57, 59, 58,
		58, 59, 60,
		57, 60, 59,
		57, 58, 60,
		61, 63, 62, //
		62, 63, 64,
		61, 64, 63,
		61, 62, 64,
		65, 67, 66, //
		66, 67, 68,
		65, 68, 67,
		65, 66, 68,
		69, 71, 70, //
		70, 71, 72,
		69, 72, 71,
		69, 70, 72,
		// Plunksnos 3
		73, 75, 74,
		74, 75, 76,
		73, 76, 75,
		73, 74, 77,
		77, 79, 78, //
		78, 79, 80,
		77, 80, 79,
		77, 78, 80,
		81, 83, 82, //
		82, 83, 84,
		81, 84, 83,
		81, 82, 84,
		85, 87, 86, //
		86, 87, 88,
		85, 88, 87,
		85, 86, 88,
		// Plunksnos 4
		89, 91, 90,
		90, 91, 92,
		89, 92, 91,
		89, 90, 92,
		93, 95, 94, //
		94, 95, 96,
		93, 96, 95,
		93, 94, 96,
		97, 99, 98, //
		98, 99, 100,
		97, 100, 99,
		97, 98, 100,
		101, 103, 102, //
		102, 103, 104,
		101, 104, 103,
		101, 102, 104

		



	};

	int indexCount = indices.size();
	SetIndexCount(indexCount);

	D3D11_BUFFER_DESC indexBufferDesc;
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA indexData;
	indexData.pSysMem = &indices[0];
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if (FAILED(result))
	{
		return false;
	}

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
	UINT  iTime = timeGetTime() % 8000;
	float fAngle = iTime * 2 * D3DX_PI / 8000.0f;
	D3DXMATRIX rotMatrix;
	//D3DXMatrixRotationY(&rotMatrix, fAngle);
	D3DXMatrixRotationY(&rotMatrix, fAngle);
	//D3DXMatrixRotationAxis(&rotMatrix, 1.0f, 1.0f,1.0f, fAngle );
	SetModelWorldMatrix(rotMatrix);
	//SetModelWorldMatrix(XMMatrixIdentity());

	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(deviceContext);

	return;
}