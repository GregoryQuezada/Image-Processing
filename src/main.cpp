#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Image
{

public:
	struct Header
	{
		char idLength;
		char colorMapType;
		char dataTypeCode;
		short colorMapOrigin;
		short colorMapLength;
		char colorMapDepth;
		short xOrigin;
		short yOrigin;
		short width;
		short height;
		char bitsPerPixel;
		char imageDescriptor;
	};

	struct Pixel
	{
		unsigned char B;
		unsigned char G;
		unsigned char R;
	};

	Header info;
	vector<Pixel> data;

	Image(Header info, vector<Pixel>& data)
	{
		this->info = info;
		this->data = data;
	}


};

void ReadBinary(string file, vector<Image>& imageList);
void WriteBinary(string file, Image& image);
void PrintHeaderInfo(Image& image);
bool DoesImageMatch(Image& imageOne, Image& imageTwo);
void Multiply(Image& imageOne, Image& imageTwo, vector<Image>& imageList);
void Subtract(Image& imageOne, Image& imageTwo, vector<Image>& imageList);
void Screen(Image& imageOne, Image& imageTwo, vector<Image>& imageList);
void Overlay(Image& imageOne, Image& imageTwo, vector<Image>& imageList);
void AddToG(Image& imageOne, vector<Image>& imageList);
void Scale(Image& imageOne, vector<Image>& imageList);
void Split(Image& imageOne, vector<Image>& imageList);
void Combine(Image& imageBlue, Image& imageGreen, Image& imageRed, vector<Image>& imageList);
void FlipBinary(Image& imageOne, vector<Image>& imageList);
void QuadrantImage(Image& imageOne, Image& imageTwo, Image& imageThree, Image& imageFour, vector<Image>& imageList);

int main()
{
	vector<Image> imageList;


	ReadBinary("input/layer1.tga", imageList);
	ReadBinary("input/pattern1.tga", imageList);
	Multiply(imageList[0], imageList[1], imageList);
	WriteBinary("output/part1.tga", imageList[2]);
	ReadBinary("examples/EXAMPLE_part1.tga", imageList);

	if (DoesImageMatch(imageList[2], imageList[3]))
		cout << "Passed!\n";
	else

		cout << "Failed!\n";

	imageList.clear();


	ReadBinary("input/layer2.tga", imageList);
	ReadBinary("input/car.tga", imageList);
	Subtract(imageList[0], imageList[1], imageList);
	WriteBinary("output/part2.tga", imageList[2]);
	ReadBinary("examples/EXAMPLE_part2.tga", imageList);

	if (DoesImageMatch(imageList[2], imageList[3]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n";

	imageList.clear();


	ReadBinary("input/layer1.tga", imageList);
	ReadBinary("input/pattern2.tga", imageList);
	Multiply(imageList[0], imageList[1], imageList);
	ReadBinary("input/text.tga", imageList);
	Screen(imageList[3], imageList[2], imageList);
	WriteBinary("output/part3.tga", imageList[4]);
	ReadBinary("examples/EXAMPLE_part3.tga", imageList);

	if (DoesImageMatch(imageList[4], imageList[5]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n";

	imageList.clear();


	ReadBinary("input/layer2.tga", imageList);
	ReadBinary("input/circles.tga", imageList);
	Multiply(imageList[0], imageList[1], imageList);
	ReadBinary("input/pattern2.tga", imageList);
	Subtract(imageList[3], imageList[2], imageList);
	WriteBinary("output/part4.tga", imageList[4]);
	ReadBinary("examples/EXAMPLE_part4.tga", imageList);

	if (DoesImageMatch(imageList[4], imageList[5]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n";

	imageList.clear();


	ReadBinary("input/layer1.tga", imageList);
	ReadBinary("input/pattern1.tga", imageList);
	Overlay(imageList[0], imageList[1], imageList);
	WriteBinary("output/part5.tga", imageList[2]);
	ReadBinary("examples/EXAMPLE_part5.tga", imageList);

	if (DoesImageMatch(imageList[2], imageList[3]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n";

	imageList.clear();


	ReadBinary("input/car.tga", imageList);
	AddToG(imageList[0], imageList);
	WriteBinary("output/part6.tga", imageList[1]);
	ReadBinary("examples/EXAMPLE_part6.tga", imageList);

	if (DoesImageMatch(imageList[1], imageList[2]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n";

	imageList.clear();


	ReadBinary("input/car.tga", imageList);
	Scale(imageList[0], imageList);
	WriteBinary("output/part7.tga", imageList[1]);
	ReadBinary("examples/EXAMPLE_part7.tga", imageList);

	if (DoesImageMatch(imageList[1], imageList[2]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n";

	imageList.clear();


	ReadBinary("input/car.tga", imageList);
	Split(imageList[0], imageList);
	WriteBinary("output/part8_b.tga", imageList[1]);
	WriteBinary("output/part8_g.tga", imageList[2]);
	WriteBinary("output/part8_r.tga", imageList[3]);
	ReadBinary("examples/EXAMPLE_part8_b.tga", imageList);
	ReadBinary("examples/EXAMPLE_part8_g.tga", imageList);
	ReadBinary("examples/EXAMPLE_part8_r.tga", imageList);

	if (DoesImageMatch(imageList[1], imageList[4]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n";

	if (DoesImageMatch(imageList[2], imageList[5]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n";

	if (DoesImageMatch(imageList[3], imageList[6]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n\n";

	imageList.clear();


	ReadBinary("input/layer_blue.tga", imageList);
	ReadBinary("input/layer_green.tga", imageList);
	ReadBinary("input/layer_red.tga", imageList);
	Combine(imageList[0], imageList[1], imageList[2], imageList);
	WriteBinary("output/part9.tga", imageList[3]);
	ReadBinary("examples/EXAMPLE_part9.tga", imageList);

	if (DoesImageMatch(imageList[3], imageList[4]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n\n";

	imageList.clear();

	ReadBinary("input/text2.tga", imageList);
	FlipBinary(imageList[0], imageList);
	WriteBinary("output/part10.tga", imageList[1]);
	ReadBinary("examples/EXAMPLE_part10.tga", imageList);

	if (DoesImageMatch(imageList[1], imageList[2]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n\n";

	imageList.clear();

	ReadBinary("input/car.tga", imageList);
	ReadBinary("input/circles.tga", imageList);
	ReadBinary("input/text.tga", imageList);
	ReadBinary("input/pattern1.tga", imageList);
	QuadrantImage(imageList[0], imageList[1], imageList[2], imageList[3], imageList);
	WriteBinary("output/extra_credit.tga", imageList[4]);
	ReadBinary("examples/EXAMPLE_extracredit.tga", imageList);


	/*for (int i = 0; i < imageList[4].info.height * imageList[4].info.width; i++)
	{
		cout << " A Pixel " << (i+1) << ": " << (int)imageList[4].data[i].B << " " << (int)imageList[4].data[i].G << " " << (int)imageList[4].data[i].R
			 << " B Pixel " << (i + 1) << ": " << (int)imageList[5].data[i].B << " " << (int)imageList[5].data[i].G << " " << (int)imageList[5].data[i].R << "\n";
	}*/

	if (DoesImageMatch(imageList[4], imageList[5]))
		cout << "Passed!\n";
	else
		cout << "Failed!\n\n";
}

void ReadBinary(string file, vector<Image>& imageList)
{
	ifstream binary(file, ios_base::binary);

	if (binary.is_open())
	{

		char idLength;
		binary.read((char*)&idLength, sizeof(idLength));

		char colorMapType;
		binary.read((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode;
		binary.read((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin;
		binary.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength;
		binary.read((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth;
		binary.read((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin;
		binary.read((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin;
		binary.read((char*)&yOrigin, sizeof(yOrigin));

		short width;
		binary.read((char*)&width, sizeof(width));

		short height;
		binary.read((char*)&height, sizeof(height));

		char bitsPerPixel;
		binary.read((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor;
		binary.read((char*)&imageDescriptor, sizeof(imageDescriptor));

		Image::Header info = { idLength, colorMapType, dataTypeCode, colorMapOrigin,
							   colorMapLength, colorMapDepth, xOrigin, yOrigin, width,
							   height, bitsPerPixel, imageDescriptor };

		vector<Image::Pixel> data;
		for (int j = 0; j < width * height; j++)
		{
			unsigned char B;
			binary.read((char*)&B, sizeof(B));

			unsigned char G;
			binary.read((char*)&G, sizeof(G));

			unsigned char R;
			binary.read((char*)&R, sizeof(R));

			Image::Pixel obj = { B, G, R };
			data.push_back(obj);

		}

		Image obj = Image(info, data);
		imageList.push_back(obj);

		binary.close();

	}


}

void WriteBinary(string file, Image& image)
{
	ofstream binary(file, ios_base::binary);

	if (binary.is_open())
	{

		char idLength = image.info.idLength;
		binary.write((char*)&idLength, sizeof(idLength));

		char colorMapType = image.info.colorMapType;
		binary.write((char*)&colorMapType, sizeof(colorMapType));

		char dataTypeCode = image.info.dataTypeCode;
		binary.write((char*)&dataTypeCode, sizeof(dataTypeCode));

		short colorMapOrigin = image.info.colorMapOrigin;
		binary.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));

		short colorMapLength = image.info.colorMapLength;
		binary.write((char*)&colorMapLength, sizeof(colorMapLength));

		char colorMapDepth = image.info.colorMapDepth;
		binary.write((char*)&colorMapDepth, sizeof(colorMapDepth));

		short xOrigin = image.info.xOrigin;
		binary.write((char*)&xOrigin, sizeof(xOrigin));

		short yOrigin = image.info.yOrigin;
		binary.write((char*)&yOrigin, sizeof(yOrigin));

		short width = image.info.width;
		binary.write((char*)&width, sizeof(width));

		short height = image.info.height;
		binary.write((char*)&height, sizeof(height));

		char bitsPerPixel = image.info.bitsPerPixel;
		binary.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));

		char imageDescriptor = image.info.imageDescriptor;
		binary.write((char*)&imageDescriptor, sizeof(imageDescriptor));

		/*Image::Header info = { idLength, colorMapType, dataTypeCode, colorMapOrigin,
							   colorMapLength, colorMapDepth, xOrigin, yOrigin, width,
							   height, bitsPerPixel, imageDescriptor }; */

		vector<Image::Pixel> data;
		for (int j = 0; j < image.info.width * image.info.height; j++)
		{
			unsigned char B = image.data[j].B;
			binary.write((char*)&B, sizeof(B));

			unsigned char G = image.data[j].G;
			binary.write((char*)&G, sizeof(G));

			unsigned char R = image.data[j].R;
			binary.write((char*)&R, sizeof(R));

		}

		binary.close();


	}
}

bool DoesImageMatch(Image& imageOne, Image& imageTwo)
{
	if (imageOne.info.bitsPerPixel != imageTwo.info.bitsPerPixel)
		return false;
	if (imageOne.info.colorMapDepth != imageTwo.info.colorMapDepth)
		return false;
	if (imageOne.info.colorMapLength != imageTwo.info.colorMapLength)
		return false;
	if (imageOne.info.colorMapOrigin != imageTwo.info.colorMapOrigin)
		return false;
	if (imageOne.info.colorMapType != imageTwo.info.colorMapType)
		return false;
	if (imageOne.info.dataTypeCode != imageTwo.info.dataTypeCode)
		return false;
	if (imageOne.info.height != imageTwo.info.height)
		return false;
	if (imageOne.info.idLength != imageTwo.info.idLength)
		return false;
	if (imageOne.info.imageDescriptor != imageTwo.info.imageDescriptor)
		return false;
	if (imageOne.info.width != imageTwo.info.width)
		return false;
	if (imageOne.info.xOrigin != imageTwo.info.xOrigin)
		return false;
	if (imageOne.info.yOrigin != imageTwo.info.yOrigin)
		return false;

	for (int i = 0; i < imageOne.info.width * imageOne.info.height; i++)
	{
		if (imageOne.data[i].B != imageTwo.data[i].B)
			return false;
		if (imageOne.data[i].G != imageTwo.data[i].G)
			return false;
		if (imageOne.data[i].R != imageTwo.data[i].R)
			return false;
	}

	return true;

}

void PrintHeaderInfo(Image& image)
{
	cout << "ID Length: " << (int)image.info.idLength << "\n";
	cout << "Color Map Type: " << (int)image.info.colorMapType << "\n";
	cout << "Data type code: " << (int)image.info.dataTypeCode << "\n";
	cout << "Color Map Origin: " << image.info.colorMapOrigin << "\n";
	cout << "Color Map Length: " << image.info.colorMapLength << "\n";
	cout << "Color Map Depth: " << (int)image.info.colorMapDepth << "\n";
	cout << "X Origin: " << image.info.xOrigin << "\n";
	cout << "Y Origin: " << image.info.yOrigin << "\n";
	cout << "Width: " << image.info.width << "\n";
	cout << "Height: " << image.info.height << "\n";
	cout << "Bits per pixel: " << (int)image.info.bitsPerPixel << "\n";
	cout << "Image Descriptor:" << (int)image.info.imageDescriptor << "\n";
	cout << "\n";


}

void Multiply(Image& imageOne, Image& imageTwo, vector<Image>& imageList)
{
	vector<Image::Pixel> newData;

	for (int i = 0; i < imageOne.info.height * imageOne.info.width; i++)
	{
		unsigned char B = round(((double)imageOne.data[i].B * imageTwo.data[i].B) / 255);

		unsigned char G = round(((double)imageOne.data[i].G * imageTwo.data[i].G) / 255);

		unsigned char R = round(((double)imageOne.data[i].R * imageTwo.data[i].R) / 255);

		Image::Pixel obj = { B, G, R };
		newData.push_back(obj);
	}

	Image obj = Image(imageOne.info, newData);
	imageList.push_back(obj);
}

void Screen(Image& imageOne, Image& imageTwo, vector<Image>& imageList)
{
	vector<Image::Pixel> newData;

	for (int i = 0; i < imageOne.info.height * imageOne.info.width; i++)
	{
		unsigned char B = round((1 - ((1 - (double)imageOne.data[i].B / 255) * (1 - (double)imageTwo.data[i].B / 255))) * 255);

		unsigned char G = round((1 - ((1 - (double)imageOne.data[i].G / 255) * (1 - (double)imageTwo.data[i].G / 255))) * 255);

		unsigned char R = round((1 - ((1 - (double)imageOne.data[i].R / 255) * (1 - (double)imageTwo.data[i].R / 255))) * 255);

		Image::Pixel obj = { B, G, R };
		newData.push_back(obj);
	}

	Image obj = Image(imageOne.info, newData);
	imageList.push_back(obj);
}

void Subtract(Image& imageOne, Image& imageTwo, vector<Image>& imageList)
{
	vector<Image::Pixel> newData;

	for (int i = 0; i < imageOne.info.height * imageOne.info.width; i++)
	{
		int B = imageTwo.data[i].B - imageOne.data[i].B;
		if (B > 255)
			B = 255;
		else if (B < 0)
			B = 0;

		int G = imageTwo.data[i].G - imageOne.data[i].G;
		if (G > 255)
			G = 255;
		else if (G < 0)
			G = 0;

		int R = imageTwo.data[i].R - imageOne.data[i].R;
		if (R > 255)
			R = 255;
		else if (R < 0)
			R = 0;

		Image::Pixel obj = { (unsigned char)B, (unsigned char)G, (unsigned char)R };
		newData.push_back(obj);
	}

	Image obj = Image(imageOne.info, newData);
	imageList.push_back(obj);
}

void Overlay(Image& imageOne, Image& imageTwo, vector<Image>& imageList)
{
	vector<Image::Pixel> newData;

	for (int i = 0; i < imageOne.info.height * imageOne.info.width; i++)
	{
		unsigned char B, G, R;

		if ((double)imageTwo.data[i].B / 255 <= 0.5)
			B = round(2 * ((double)imageOne.data[i].B * imageTwo.data[i].B) / 255);
		else
			B = round((1 - 2 * ((1 - (double)imageOne.data[i].B / 255) * (1 - (double)imageTwo.data[i].B / 255))) * 255);

		if ((double)imageTwo.data[i].G / 255 <= 0.5)
			G = round(2 * ((double)imageOne.data[i].G * imageTwo.data[i].G) / 255);
		else
			G = round((1 - 2 * ((1 - (double)imageOne.data[i].G / 255) * (1 - (double)imageTwo.data[i].G / 255))) * 255);

		if ((double)imageTwo.data[i].R / 255 <= 0.5)
			R = round(2 * ((double)imageOne.data[i].R * imageTwo.data[i].R) / 255);
		else
			R = round((1 - 2 * ((1 - (double)imageOne.data[i].R / 255) * (1 - (double)imageTwo.data[i].R / 255))) * 255);


		Image::Pixel obj = { B, G, R };
		newData.push_back(obj);
	}

	Image obj = Image(imageOne.info, newData);
	imageList.push_back(obj);
}

void AddToG(Image& imageOne, vector<Image>& imageList)
{
	vector<Image::Pixel> newData;

	for (int i = 0; i < imageOne.info.height * imageOne.info.width; i++)
	{

		int G = imageOne.data[i].G + 200;
		if (G > 255)
			G = 255;

		Image::Pixel obj = { imageOne.data[i].B, (unsigned char)G, imageOne.data[i].R };
		newData.push_back(obj);
	}

	Image obj = Image(imageOne.info, newData);
	imageList.push_back(obj);
}

void Scale(Image& imageOne, vector<Image>& imageList)
{
	vector<Image::Pixel> newData;

	for (int i = 0; i < imageOne.info.height * imageOne.info.width; i++)
	{
		int B = imageOne.data[i].B * 0;
		if (B > 255)
			B = 255;

		int R = imageOne.data[i].R * 4;
		if (R > 255)
			R = 255;

		Image::Pixel obj = { (unsigned char)B, imageOne.data[i].G, (unsigned char)R };
		newData.push_back(obj);
	}

	Image obj = Image(imageOne.info, newData);
	imageList.push_back(obj);
}

void Split(Image& imageOne, vector<Image>& imageList)
{
	vector<Image::Pixel> newData1, newData2, newData3;

	for (int i = 0; i < imageOne.info.height * imageOne.info.width; i++)
	{
		unsigned char B = imageOne.data[i].B;
		unsigned char G = imageOne.data[i].G;
		unsigned char R = imageOne.data[i].R;

		Image::Pixel pix1 = { B, B, B };
		Image::Pixel pix2 = { G, G, G };
		Image::Pixel pix3 = { R, R, R };

		newData1.push_back(pix1);
		newData2.push_back(pix2);
		newData3.push_back(pix3);

	}

	Image obj1 = Image(imageOne.info, newData1);
	Image obj2 = Image(imageOne.info, newData2);
	Image obj3 = Image(imageOne.info, newData3);
	imageList.push_back(obj1);
	imageList.push_back(obj2);
	imageList.push_back(obj3);
}

void Combine(Image& imageBlue, Image& imageGreen, Image& imageRed, vector<Image>& imageList)
{
	vector<Image::Pixel> newData;

	for (int i = 0; i < imageBlue.info.height * imageBlue.info.width; i++)
	{
		unsigned char B = imageBlue.data[i].B;
		unsigned char G = imageGreen.data[i].G;
		unsigned char R = imageRed.data[i].R;

		Image::Pixel obj = { B, G, R };

		newData.push_back(obj);
	}

	Image obj = Image(imageBlue.info, newData);
	imageList.push_back(obj);
}

void FlipBinary(Image& imageOne, vector<Image>& imageList)
{
	vector<Image::Pixel> newData;

	for (int i = (imageOne.info.height * imageOne.info.width) - 1; i >= 0; i--)
	{
		unsigned char B = imageOne.data[i].B;
		unsigned char G = imageOne.data[i].G;
		unsigned char R = imageOne.data[i].R;

		Image::Pixel obj = { B, G, R };

		newData.push_back(obj);
	}

	Image obj = Image(imageOne.info, newData);
	imageList.push_back(obj);


}

void QuadrantImage(Image& imageOne, Image& imageTwo, Image& imageThree, Image& imageFour, vector<Image>& imageList)
{
	vector<Image::Pixel> newData;
	int indexOne = 0;
	int indexTwo = 0;
	int indexThree = 0;
	int indexFour = 0;
	int count = 1;

	for (int i = 0; i < ((imageOne.info.height + imageThree.info.height) * (imageOne.info.width + imageTwo.info.width)); i++)
	{
		unsigned char B;
		unsigned char G;
		unsigned char R;

		if (count == 1 || count == 2)
		{
			if ((((i % imageThree.info.width) != 0) && (i < ((imageThree.info.width + imageFour.info.width) * imageThree.info.height)) && count == 1) || i == 0)
			{
				B = imageThree.data[indexThree].B;
				G = imageThree.data[indexThree].G;
				R = imageThree.data[indexThree].R;
				indexThree++;
			}
			else
			{
				count = 2;
			}


			if ((i % (imageThree.info.width + imageFour.info.width) != 0) && (i < ((imageThree.info.width + imageFour.info.width) * imageThree.info.height)) && count == 2)
			{

				B = imageFour.data[indexFour].B;
				G = imageFour.data[indexFour].G;
				R = imageFour.data[indexFour].R;
				indexFour++;

			}
			else if (i == ((imageThree.info.width + imageFour.info.width) * imageThree.info.height))
			{
				count = 3;

			}
			else if (((i % imageThree.info.width) == 0) && (i < ((imageThree.info.width + imageFour.info.width) * imageThree.info.height)) && count == 2)
			{
				count = 1;
				B = imageThree.data[indexThree].B;
				G = imageThree.data[indexThree].G;
				R = imageThree.data[indexThree].R;
				indexThree++;

			}
		}

		if (count == 3 || count == 4)
		{
			if ((((i % imageOne.info.width) != 0) && (i < ((imageOne.info.width + imageTwo.info.width) * (imageOne.info.height * imageTwo.info.height))) && count == 3))
			{
				B = imageOne.data[indexOne].B;
				G = imageOne.data[indexOne].G;
				R = imageOne.data[indexOne].R;
				indexOne++;

			}
			else
			{
				count = 4;
			}



			if ((i % (imageOne.info.width + imageTwo.info.width) != 0) && (i < ((imageOne.info.width + imageTwo.info.width) * (imageOne.info.height * imageTwo.info.height))) && count == 4)
			{

				B = imageTwo.data[indexTwo].B;
				G = imageTwo.data[indexTwo].G;
				R = imageTwo.data[indexTwo].R;
				indexTwo++;

			}
			else if (i == ((imageOne.info.width + imageTwo.info.width) * (imageOne.info.height + imageTwo.info.height)))
			{
				count = 5;
			}
			else if (((i % imageOne.info.width) == 0) && (i < ((imageOne.info.width + imageTwo.info.width) * (imageOne.info.height * imageTwo.info.height))) && count == 4)
			{
				count = 3;
				B = imageOne.data[indexOne].B;
				G = imageOne.data[indexOne].G;
				R = imageOne.data[indexOne].R;
				indexOne++;

			}
		}

		//cout << i << " Count: " << count << "\n";

		Image::Pixel obj = { B, G, R };

		newData.push_back(obj);
	}

	Image obj = Image(imageOne.info, newData);
	obj.info.height = (imageOne.info.height + imageThree.info.height);
	obj.info.width = (imageOne.info.width + imageTwo.info.width);
	imageList.push_back(obj);
}