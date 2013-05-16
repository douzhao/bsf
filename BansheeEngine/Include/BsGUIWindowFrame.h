#pragma once

#include "BsPrerequisites.h"
#include "BsGUIElement.h"
#include "BsImageSprite.h"

namespace BansheeEngine
{
	class BS_EXPORT GUIWindowFrame : public GUIElement
	{
	public:
		static const CM::String& getGUITypeName();

		static GUIWindowFrame* create(GUIWidget& parent);
		static GUIWindowFrame* create(GUIWidget& parent, const GUI_LAYOUT_OPTIONS& layoutOptions);
	protected:
		~GUIWindowFrame();

		/**
		 * @copydoc GUIElement::getNumRenderElements()
		 */
		virtual UINT32 getNumRenderElements() const;

		/**
		 * @copydoc GUIElement::getMaterial()
		 */
		virtual const CM::HMaterial& getMaterial(UINT32 renderElementIdx) const;

		/**
		 * @copydoc GUIElement::getNumQuads()
		 */
		virtual UINT32 getNumQuads(UINT32 renderElementIdx) const;

		/**
		 * @copydoc GUIElement::fillBuffer()
		 */
		virtual void fillBuffer(UINT8* vertices, UINT8* uv, UINT32* indices, UINT32 startingQuad, 
			UINT32 maxNumQuads, UINT32 vertexStride, UINT32 indexStride, UINT32 renderElementIdx) const;

		/**
		 * @copydoc GUIElement::updateRenderElementsInternal()
		 */
		virtual void updateRenderElementsInternal();

		static const GUI_LAYOUT_OPTIONS& getDefaultLayoutOptions();
	private:
		ImageSprite* mImageSprite;
		IMAGE_SPRITE_DESC mDesc;

		GUIWindowFrame(GUIWidget& parent, const GUI_LAYOUT_OPTIONS& layoutOptions);
	};
}