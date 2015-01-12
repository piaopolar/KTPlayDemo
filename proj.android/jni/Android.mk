LOCAL_PATH := $(call my-dir)

#prebuild KTPlay library
include $(CLEAR_VARS)
LOCAL_MODULE := libKTPlay
LOCAL_SRC_FILES := libKTPlay.so
LOCAL_MODULE_FILENAME := libKTPlay
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libKTAccountmanager
LOCAL_SRC_FILES := libKTAccountmanager.so
LOCAL_MODULE_FILENAME := libKTAccountmanager
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libKTFriendship
LOCAL_SRC_FILES := libKTFriendship.so
LOCAL_MODULE_FILENAME := libKTFriendship
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libKTLeaderboard
LOCAL_SRC_FILES := libKTLeaderboard.so
LOCAL_MODULE_FILENAME := libKTLeaderboard
include $(PREBUILT_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

LOCAL_SHARED_LIBRARIES := libKTPlay libKTAccountmanager libKTFriendship libKTLeaderboard

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
