//
//  KeyframeTrackController.cpp
//  tracksAndTimeTest
//
//  Created by Roy Macdonald on 3/17/20.
//

#include "LineaDeTiempo/Controller/KeyframeTrackController.h"

#include "LineaDeTiempo/Controller/TrackGroupController.h"

#include "LineaDeTiempo/Utils/ofxTypeTraits.h"
//#include "LineaDeTiempo/View/MultiDimTrackView.h"


namespace ofx {
namespace LineaDeTiempo {
//
template <typename T>
KeyframeTrackController_<T>::KeyframeTrackController_(ofParameter<T>& parameter,TrackGroupController* parent, TimeControl* timeControl)
: TrackController(parameter.getName(), parent, timeControl)
{
	
	_parameter.makeReferenceTo(parameter);
	_setup();
}

template <typename T>
KeyframeTrackController_<T>::KeyframeTrackController_(const std::string& name, TrackGroupController* parent, TimeControl* timeControl)
: TrackController(name, parent, timeControl)
{
	_parameter.setName(name);
	
	_setup();
	
}

template <typename T>
void KeyframeTrackController_<T>::_setup()
{

		
	//	_paramListener = _parameter.newListener(this, &KeyframeTrackController_<T>::_paramChanged);
	
	this->enableTimeUpdate();
	_dataTypeName = typeid(T).name();
	
}


template <typename T>
KeyframeRegionController_<T> * KeyframeTrackController_<T>::addRegion( const std::string& regionName)
{
	auto r = _addRegion<KeyframeRegionController_<T>>( regionName, ofRange64u(0, getTimeControl()->getTotalTime()));
	return r;
}


template <typename T>
KeyframeRegionController_<T> * KeyframeTrackController_<T>::addRegion( const std::string& regionName, const ofRange64u& timeRange)
{
	auto r = _addRegion<KeyframeRegionController_<T>>( regionName, timeRange);
	return r;
}

template <typename T>
ofParameter<T>& KeyframeTrackController_<T>::getParameter()
{
	return _parameter;
}

template <typename T>
const ofParameter<T>& KeyframeTrackController_<T>::getParameter() const
{
	return _parameter;
}


template <typename T>
void KeyframeTrackController_<T>::_paramChanged(T& ){
	//	if(!_bModifyingParam)
	//	{
	//		_keyframedData.setValue(_parameter, getTimeControl()->getCurrentTime(), _keyframedData.isKeyFramingEnabled() );
	//	}
}


template <typename T>
void KeyframeTrackController_<T>::_addRegionFromJson(const std::string& name, ofJson j)
{
	addRegion(name)->fromJson(j);
}


template <typename T>
void KeyframeTrackController_<T>::fromJson(const ofJson& j)
{
	if(	j.count("class") > 0 && j.count("name") > 0){
		auto clss = j["class"].get<std::string>();
		if(clss != "KeyframeTrackController_")
		{
			ofLogError("KeyframeTrackController_<T>::fromJson") << "failed. class name stored in json is different from this one : " << clss;
			return;
		}
		
		auto dt = j["_dataTypeName"].get<std::string>();
		
		if(dt != std::string(typeid(T).name()))
		{
			ofLogError("KeyframeTrackController_<T>::fromJson") << "failed. T seems to be different to the one saved on file";
			return;
		}
		
		TrackController::fromJson(j);
		
	}
	else{
		ofLogError("KeyframeTrackController_<T>::fromJson") << "json malformed. No class or name objects.";
	}
	
}

template <typename T>
ofJson KeyframeTrackController_<T>::toJson()
{
	
	ofJson j = TrackController::toJson();
	j["class"] = "KeyframeTrackController_";
	j["name"] = getId();
	j["view"] = bool(getView());
	
	
	
	
	return j;
}

} } // ofx::LineaDeTiempo

//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofRectangle>;

//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofColor_<char>>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofColor_<unsigned char>>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofColor_<short>>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofColor_<unsigned short>>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofColor_<int>>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofColor_<unsigned int>>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofColor_<long>>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofColor_<unsigned long>>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofColor_<float>>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofColor_<double>>;

template class ofx::LineaDeTiempo::KeyframeTrackController_<glm::vec2>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<glm::vec3>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<glm::vec4>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<glm::quat>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<glm::mat4>;
//
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofVec2f>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofVec3f>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<ofVec4f>;

//template class ofx::LineaDeTiempo::KeyframeTrackController_<bool>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<void>;

template class ofx::LineaDeTiempo::KeyframeTrackController_<char>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<unsigned char>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<signed char>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<short>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<unsigned short>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<int>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<unsigned int>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<long>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<unsigned long>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<long long>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<unsigned long long>;
template class ofx::LineaDeTiempo::KeyframeTrackController_<float>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<double>;
//template class ofx::LineaDeTiempo::KeyframeTrackController_<long double>;






