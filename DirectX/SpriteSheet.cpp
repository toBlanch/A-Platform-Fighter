#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(LPCWSTR filename, Graphics* graphics)
{
	gfx = graphics;
	bmp = NULL;
	HRESULT hr;

	IWICImagingFactory* wicFactory = NULL;
	hr = CoCreateInstance(
		CLSID_WICImagingFactory, //CLS ID of the object we're making
		NULL, //Not part of an aggregate
		CLSCTX_INPROC_SERVER, //DLL runs in the same proceess
		IID_IWICImagingFactory, //Ref to interface that communicates with the object
		(LPVOID*)&wicFactory //The pointer that'll cointain our factory
	); 

	IWICBitmapDecoder* wicDecoder = NULL;
	hr = wicFactory->CreateDecoderFromFilename(
		filename, //Filename
		NULL, //No preferred vendor
		GENERIC_READ, //Only reading
		WICDecodeMetadataCacheOnLoad, //Cache on load*
		&wicDecoder
	);

	//Read the image
	IWICBitmapFrameDecode* wicFrame = NULL;
	hr = wicDecoder->GetFrame(0, &wicFrame);

	IWICFormatConverter* wicConverter = NULL;
	hr = wicFactory->CreateFormatConverter(&wicConverter);

	hr = wicConverter->Initialize(
		wicFrame, //Frame
		GUID_WICPixelFormat32bppPBGRA, //Pixel Format
		WICBitmapDitherTypeNone, //Irrelevant
		NULL, //No pallete needed
		0.0, //Alpha transparency % irrelevant
		WICBitmapPaletteTypeCustom //Irrlrvant
	);

	gfx->GetRenderTarget()->CreateBitmapFromWicBitmap(
		wicConverter, //Converter
		NULL, //D2D1_BITMAP_PROPERTIES
		&bmp //Destination bitmap
	);

	if (wicFactory) wicFactory->Release();
	if (wicDecoder)wicDecoder->Release();
	if (wicConverter) wicConverter->Release();
	if (wicFrame)wicFrame->Release();
}

SpriteSheet::~SpriteSheet()
{
	if (bmp) bmp->Release();
	if (bmpFlip) bmpFlip->Release();
}

void SpriteSheet::Draw(int x0, int y0, bool flip)
{
	if (flip) {
		gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F(-1, 0, 0, 1, 0, 0));
		x0 = -(x0 + bmp->GetSize().width);
	}
	gfx->GetRenderTarget()->DrawBitmap(
		bmp, //Bitmap
		D2D1::RectF(
			x0, //X0
			y0, //Y0
			x0 + bmp->GetSize().width, //X1
			y0 + bmp->GetSize().height), //Y1
		1, //Opacity
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(0, 0, bmp->GetSize().width, bmp->GetSize().height) //Source rectangle
	);
	if (flip) {
		gfx->GetRenderTarget()->SetTransform(D2D1::Matrix3x2F(1, 0, 0, 1, 0, 0));
	}
}
