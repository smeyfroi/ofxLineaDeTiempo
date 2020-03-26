//
//  Keyframe.hpp
//  keyframesTest
//
//  Created by Roy Macdonald on 2/14/20.
//

#pragma once
#include "ofx/MUI/Widget.h"
#include "LineaDeTiempo/BaseTypes/BaseSelectable.h"
namespace ofx {
namespace LineaDeTiempo {

class KeyframesRegionView;
class KeyframeView
: public MUI::Widget
, public BaseSelectable
{
private:
	KeyframeView(const std::string& id, KeyframesRegionView * parentRegionView);
	
public:
	
	friend class KeyframesRegionView;
	KeyframeView(const std::string& id, const glm::vec2& pos, KeyframesRegionView * parentRegionView);
	KeyframeView(const std::string& id, float value, uint64_t time,  KeyframesRegionView * parentRegionView);
	
	
	virtual ~KeyframeView(){}
	

	virtual void onDraw() const override;
	
	
	virtual void setSelected(bool select) override;
		
	
	static float defaultKeyframeSize;
	
	
	float getValue() const;
	uint64_t getTime() const;
	
	ofEvent<float> valueChangedEvent;
	ofEvent<uint64_t> timeChangedEvent;
protected:
	KeyframesRegionView * _parentRegionView = nullptr;

	uint64_t _time = 0;
	float _value =0; //normalized

	void _updatePosition();
	void _updateValue();
	
	virtual void _onDragging(const DOM::CapturedPointer& pointer) override;
	
    virtual void _onPointerEvent(DOM::PointerUIEventArgs& e) override;

//	bool bSelected = false;
	
	bool _moved = false;
};


} } // ofx::LineaDeTiempo
