#pragma once

#include "CmD3D11Prerequisites.h"
#include "CmHardwareBufferManager.h"

namespace CamelotEngine
{
	class CM_D3D11_EXPORT D3D11HardwareBufferManagerBase : public HardwareBufferManagerBase
	{
	public:
		D3D11HardwareBufferManagerBase(D3D11Device& device);
		~D3D11HardwareBufferManagerBase();

		/**
		 * @brief	Creates a hardware vertex buffer.
		 */
		HardwareVertexBufferPtr createVertexBuffer(UINT32 vertexSize, UINT32 numVerts, HardwareBuffer::Usage usage, bool streamOut = false);
		
		/**
		 * @brief	Creates a hardware index buffer.
		 */
		HardwareIndexBufferPtr createIndexBuffer(HardwareIndexBuffer::IndexType itype, UINT32 numIndexes, HardwareBuffer::Usage usage);

		/** @copydoc HardwareBufferManagerInterface::createGpuParamBlock */
		GpuParamBlockPtr createGpuParamBlock(const GpuParamBlockDesc& paramDesc);

	protected:     
		/// Internal method for creates a new vertex declaration, may be overridden by certain rendering APIs
		VertexDeclarationPtr createVertexDeclarationImpl(void);
		/// Internal method for destroys a vertex declaration, may be overridden by certain rendering APIs
		void destroyVertexDeclarationImpl(VertexDeclaration* decl);

		D3D11Device& mDevice;
	};

	class CM_D3D11_EXPORT D3D11HardwareBufferManager : public HardwareBufferManager
	{
	public:
		D3D11HardwareBufferManager(D3D11Device& device)
			: HardwareBufferManager(new D3D11HardwareBufferManagerBase(device)) 
		{ }

		~D3D11HardwareBufferManager()
		{
			delete mImpl;
		}
	};
}