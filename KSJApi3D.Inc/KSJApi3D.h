#ifndef __KSJ_API_3D_H__
#define __KSJ_API_3D_H__


#ifdef KSJAPI_EXPORTS
#define KSJ_API __declspec(dllexport)
#elif defined KSJAPI_STATIC
#define KSJ_API
#else
#define KSJ_API __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"{
#endif
	
	/*
	��ʼ���ͷ���ʼ��
	*/
	KSJ_API  int __stdcall KSJ3D_Inital();
	KSJ_API  int __stdcall KSJ3D_UnInitial();

	/*
	ȡ�ÿ�汾
	*/
	KSJ_API  int __stdcall KSJ3D_GetAPIVersion(int *pnMaj1, int *pnMaj2, int *pnMin1, int *pnMin2);
	
	/*
	ȡ������ĸ���
	*/
	KSJ_API  int __stdcall KSJ3D_GetDeviceCount(int *pnCount);

	/*
	ȡ���������Ϣ
	*/
	KSJ_API  int __stdcall KSJ3D_GetDeviceInformation(int nChannel, int* pnDeviceType, int* pnSerialNumber, unsigned short *pwFirmwareVersion, unsigned short *pwFpgaVersion);
	
	/*
	����Ƿ���3D���
	*/
	KSJ_API  int __stdcall KSJ3D_Is3DCamera(int nChannel, bool* pb3DCamera);
	
	/*
	ȡ��ʵʱͼ��ص��ӿ�����
	*/
	typedef void(__stdcall *KSJ_LIVE_IMAGE_CALLBACK)(int nChannel, unsigned char *pData, int nWidth, int nHeight, int nBitCount, void *lpContext);
	KSJ_API  int __stdcall KSJ3D_RegisterLiveImageCB(int nChannel, KSJ_LIVE_IMAGE_CALLBACK pfCallback, void *lpContext);

	// nLostProfileNum��ǰprofile����һ��profile֮�䶪ʧ�˶��ٸ�profile��nProfileIndexˮӡ���
	typedef void(__stdcall *KSJ_PROFILE_DATA_CALLBACK)(int nChannel, int nPointNum, float fYMillimeters, int nProfileIndex, float *x, float *z, int nLostProfileNum, void *lpContext);
	// ��ȡ��Profile���ݣ�x��z
	KSJ_API  int __stdcall KSJ3D_RegisterProfileDataCB(int nChannel, KSJ_PROFILE_DATA_CALLBACK pfCallback, void *lpContext);

	/*
	ȡ��profileͼ��ص��ӿ�����
	*/
	typedef void(__stdcall *KSJ_PROFILE_IMAGE_CALLBACK)(int nChannel, unsigned char *pData, int nWidth, int nHeight, int nBitCount, void *lpContext);
	// ͨ��zmapת����profileͼ��
	KSJ_API  int __stdcall KSJ3D_RegisterProfileImageCB(int nChannel, KSJ_PROFILE_IMAGE_CALLBACK pfCallback, void *lpContext);

	// nTotalLostProfileNum���ĵ������ݹ���ʧ�˶��ٸ�profile��nProfileNum��ʾʵ�ʲɼ���profile��x,y,z����Ԫ�ظ�����ҪΪnPointNum��
	typedef void(__stdcall *KSJ_POINT_CLOUD_DATA_CALLBACK)(int nChannel, int nTotalPointNum, int nProfileNum, float *x, float *y, float *z, int nTotalLostProfileNum, void *lpContext);
	// ��ȡ�ϳɵ�profile 3d�������ݣ�x��y��z
	KSJ_API  int __stdcall KSJ3D_RegisterPointCloudDataCB(int nChannel, KSJ_POINT_CLOUD_DATA_CALLBACK pfCallback, void *lpContext);

	/*
	ȡ�õ������ݻص��ӿ�����
	*/
	typedef void(__stdcall *KSJ_POINT_CLOUD_IMAGE_CALLBACK)(int nChannel, unsigned char *pData, int nWidth, int nHeight, int nBitCount, void *lpContext);
	// ��ȡzmapת����3dͼ��
	KSJ_API  int __stdcall KSJ3D_RegisterPointCloudImageCB(int nChannel, KSJ_POINT_CLOUD_IMAGE_CALLBACK pfCallback, void *lpContext);
	
	/*
	����ROI
	*/
	KSJ_API  int __stdcall KSJ3D_GetRoiMax(int nChannel, int* pnColMax, int* pnRowMax);
	KSJ_API  int __stdcall KSJ3D_SetRoi(int nChannel, int nColStart, int nRowStart, int nColSize, int nRowSize);
	KSJ_API  int __stdcall KSJ3D_GetRoi(int nChannel, int* pnColStart, int* pnRowStart, int* pnColSize, int* pnRowSize);

	/*
	��������ع�
	*/
	KSJ_API  int __stdcall KSJ3D_GetExposureTimeRange(int nChannel, float* pfExpTimeMSMin, float* pfExpTimeMSMax);
	KSJ_API  int __stdcall KSJ3D_SetExposureTime(int nChannel, float fExpTimeMS);
	KSJ_API  int __stdcall KSJ3D_GetExposureTime(int nChannel, float* pfExpTimeMS);

	/*
	�����������
	*/
	KSJ_API  int __stdcall KSJ3D_GetGainRange(int nChannel, int* pnGainMin, int* pnGainMax);
	KSJ_API  int __stdcall KSJ3D_SetGain(int nChannel, int nGain);
	KSJ_API  int __stdcall KSJ3D_GetGain(int nChannel, int* pnGain);

	/*
	���ù�����ʼ�Ĵ���ģʽ
	StartTriggerSource - �����ʱ�ȱ�����Ŀǰ������Ҫ���ã�ʹ��Ĭ�ϵľ���
	enable - �Ƿ����ÿ�ʼ�ɼ��ź�
	TriggerEdgeMode - ��ʼ�źŵ�ģʽ
	*/
	enum  	KSJ3D_START_TRIGGER_SOURCE {
		STS_INPUT_0 = 0,     // Ŀǰֻ��һ��start trigger����Դ
	};

	enum  	KSJ3D_TRIGGER_EDGE_MODE {
		TEM_RISING_EDGE = 0,
		TEM_FALLING_EDGE = 1
	};
	
	KSJ_API  int __stdcall KSJ3D_SetStartTrigger(int nChannel, KSJ3D_START_TRIGGER_SOURCE  StartTriggerSource,  bool bEnable,  KSJ3D_TRIGGER_EDGE_MODE  StartTriggerCondition);
	KSJ_API  int __stdcall KSJ3D_GetStartTrigger(int nChannel, KSJ3D_START_TRIGGER_SOURCE *pStartTriggerSource, bool *pbEnable, KSJ3D_TRIGGER_EDGE_MODE *pStartTriggerCondition);

	/*
	����Start�����źŲ���
	triggerFilter - �ź��˲�
	*/
	KSJ_API  int __stdcall KSJ3D_SetStartTriggerParameters(int nChannel, int StartTriggerFilter, int nStartTriggerDelay);
	KSJ_API  int __stdcall KSJ3D_GetStartTriggerParameters(int nChannel, int* pStartTriggerFilter, int *pnStartTriggerDelay);

	// �������ݴ���ģʽ
	enum  	KSJ3D_DATA_TRIGGER_MODE
	{
		DTM_FREE_RUN = 0,            // ���ɴ�����������֡�ʽ��д���
		DTM_INTERNAL = 1,            // �ڲ����ݴ���Ƶ�����ý����Զ�����
		DTM_EXTERNAL = 2             // �����ⲿ�����źŽ��д���
	};
	KSJ_API  int __stdcall KSJ3D_SetDataTriggerMode(int nChannel, KSJ3D_DATA_TRIGGER_MODE DataTriggerMode);
	KSJ_API  int __stdcall KSJ3D_GetDataTriggerMode(int nChannel, KSJ3D_DATA_TRIGGER_MODE *pDataTriggerMode);

	// ������DTM_INTERNAL���ݴ���ģʽ�µĴ���Ƶ��
	KSJ_API  int __stdcall KSJ3D_SetDataTriggerInternalFrequency(int nChannel, int nInternalFrequencyHz);
	KSJ_API  int __stdcall KSJ3D_GetDataTriggerInternalFrequency(int nChannel, int *pnInternalFrequencyHz);

	/*
	���������ⴥ���źŲ���
	nTriggerDivider - ����źŴ���һ��
	nTriggerDelay - ��ʼ�����ź���
	nTriggerFilter - �ź��˲�
	DataTriggerCondition - �ź�Method��������/�½���
	*/
	// ������DTM_EXTERNAL���ݴ���ģʽ�µ�������ã���Ƶ����ʱ���˲�������ģʽ��
	KSJ_API  int __stdcall KSJ3D_SetDataTriggerExternalTriggerParameters(int nChannel, int nDataTriggerDivider, int nDataTriggerDelay, int nDataTriggerFilter, KSJ3D_TRIGGER_EDGE_MODE DataTriggerCondition);
	KSJ_API  int __stdcall KSJ3D_GetDataTriggerExternalTriggerParameters(int nChannel, int *pnDataTriggerDivider, int *pnDataTriggerDelay, int* pnDataTriggerFilter, KSJ3D_TRIGGER_EDGE_MODE *pDataTriggerCondition);


	/*
	����3D����ͼ���profiles����Ŀǰ��Ӧ���ǵ�multi line��
	*/
	KSJ_API  int __stdcall KSJ3D_SetMaxNumberOfProfilesToCapture(int nChannel, int nNumberOfProfiles);
	KSJ_API  int __stdcall KSJ3D_GetMaxNumberOfProfilesToCapture(int nChannel, int* pNumberOfProfiles);


	/*
	��ʼ��ֹͣ3D����(�ɼ�)�߳�
	*/
	KSJ_API  int __stdcall KSJ3D_StartAcquisition(int nChannel);
	KSJ_API  int __stdcall KSJ3D_StopAcquisition(int nChannel);



	// nThreadhold [0-255], �Ҷ�ֵ���ޣ����ڼ���profile����ֵ
	KSJ_API  int __stdcall KSJ3D_Set3DLaserLineBrightnessThreshold(int nChannel, int nThreshold);
	KSJ_API  int __stdcall KSJ3D_Get3DLaserLineBrightnessThreshold(int nChannel, int *pnThreshold);

	enum KSJ_LASER_MODE
	{
		LM_NORMAL_OPEN = 0,
		LM_NORMAL_CLOSE = 1,
		LM_FLASH
	};
	// �����߼��⹤��ģʽ�����������ء�Ƶ��
	KSJ_API  int __stdcall KSJ3D_LaserModeSet(int nChannel, KSJ_LASER_MODE LaserMode);
	KSJ_API  int __stdcall KSJ3D_LaserModeGet(int nChannel, KSJ_LASER_MODE *pLaserMode);

	
	// �õ��߶Ȳ�����Χ��������Ұ��Զ����Ұ
	KSJ_API  int __stdcall KSJ3D_GetMeasurementRange(int nChannel, float *pfZMin, float *pfZMax, float *pfFovNear, float *pfFovFar);

	// �����߶Ȳ�������ת��ͼ��Ҷ����ݵ���ʾЧ����fZMin(mm)ӳ��Ϊ�Ҷ�ֵ0��fZMax��mm��ӳ��Ϊ�Ҷ�ֵ255
	KSJ_API  int __stdcall KSJ3D_SetZMap(int nChannel, float fZMin, float fZMax);
	KSJ_API  int __stdcall KSJ3D_GetZMap(int nChannel, float *pfZMin, float *pfZMax);

	// Y�����˶����򣩵ķֱ���
	KSJ_API  int __stdcall KSJ3D_SetYResolution(int nChannel, float fYResolution);
	KSJ_API  int __stdcall KSJ3D_GetYResolution(int nChannel, float *pfYResolution);

	// ����֡�ʣ�����ˮӡʱ����㣬ʵ�ʻ�ȡ��֡��
	KSJ_API  int __stdcall KSJ3D_GetTransmissionRate(int nChannel, float *pfTransmissionRate);

	// �����Ƕ�֡������ˮӡ�ļ�����ʱ�����
	KSJ_API  int __stdcall KSJ3D_GetExternalTriggerRate(int nChannel, float *pfExternalTriggerRateHz);


	// KSJ3D_StartAcquisition�������������
	// KSJ_API  int __stdcall KSJ3D_CaptureLiveImage(int nChannel, unsigned char *pLiveImageData, int *pnWidth, int *pnHeight, int *pnBitCount);
	// ����image���ݣ�����profile�궨��Ĳ������ݣ�KSJ3D_StartAcquisition�������������
	// KSJ_API  int __stdcall KSJ3D_CalculateProfileDataFromImage(int nChannel, unsigned char *pLiveImageData, float *pfX, float *pfZ);
	// KSJ_API  int __stdcall KSJ3D_MapProfileDataToImage(int nChannel, float *pfX, float *pfZ, int nPointNum);



#ifdef __cplusplus
}
#endif

#endif
