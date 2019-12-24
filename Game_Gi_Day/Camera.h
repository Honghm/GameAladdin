#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "define.h" 

class Camera
{
protected:
	float _xCam;
	float _yCam;

	float _xCamBackup;
	float _yCamBackup;
	float _boundaryLeftBackup;
	float _boundaryRightBackup;
	float _boundaryTopBackup;
	float _boundaryBottomBackup;

	int _width;
	int _height;

	float _boundaryLeft; // biên giới hạn bên trái 
	float _boundaryRight; // biên giới hạn bên phải
	float _boundaryTop; // biên giới hạn bên trên 
	float _boundaryBottom; // biên giới hạn bên dưới

	float vx;
	DWORD dt;
	D3DXVECTOR3 postion;
	bool isAllowFollowAladdin;

public:
	Camera(int w, int h);
	~Camera();

	void Update(DWORD dt);

	D3DXVECTOR2 Transform(float, float);

	void SetPosition(float x, float y);

	float GetXCam();
	float GetYCam();
	int GetWidth();
	int GetHeight();
	D3DXVECTOR3 GetPostion();
	bool checkObjectInCamera(float x, float y, float w, float h);

	bool AllowFollowAladdin();
	void SetAllowFollowAladdin(bool b);

	void SetBoundary(float left, float right, float top, float bottom); // set biên giới hạn cho camera
	float GetBoundaryRight();
	float GetBoundaryLeft();
	float GetBoundaryTop();
	float GetBoundaryBottom();

	void SetPositionBackup(float X, float Y);
	void RestorePosition();

	void SetBoundaryBackup(float l, float r, float t, float b);
	void RestoreBoundary();
};

#endif



