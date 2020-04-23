//
//  ZoomablePanel.hpp
//  example
//
//  Created by Roy Macdonald on 4/20/20.
//


#pragma once

//#include "ofxMUI.h"
#include "MUI/ZoomScrollbar.h"
#include "MUI/ClippedView.h"

#include "MUI/Constants.h"
#include "DOM/Element.h"

namespace ofx {
namespace MUI {



template<typename ClippedViewType, typename ClippedContainerType>
class ZoomablePanel: public DOM::Element
{
public:

	ZoomablePanel(const std::string& id, const ofRectangle& rect);
	
	virtual ~ZoomablePanel() = default;

	bool isScrollbarActive(DOM::Orientation scrollbarOrientation);
	float getScrollbarSize(DOM::Orientation scrollbarOrientation);
	
	ClippedViewType* getClippingView();
	
	ClippedContainerType*  getContainer();
	
	
	
	
	void setForceShowScrollbars(bool show);
	bool isForceShowScrollbars();
	
	void setScrollH(const ofRange& d);
	void setScrollV(const ofRange& d);
	
	
	void updateVerticalScrollFromContainersHeight();
	
protected:
	
	ClippedViewType* _clippingPanel = nullptr;
	
	
	virtual void _onShapeChange(const DOM::ShapeChangeEventArgs& ) override;
	
	
	bool _forceShowScrollbars = false;
	
	ZoomScrollbar * _scrollbarH = nullptr;
	ZoomScrollbar * _scrollbarV = nullptr;
	ofEventListeners _scrollbarsListeners;
	


private:

};

} } // ofx::MUI



