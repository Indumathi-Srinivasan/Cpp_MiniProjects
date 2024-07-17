//Basic Opencv C++ 

#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<vector>
#include<string>


int main()
{

	/*
	std::string path = "sample.jpg";   
	cv::Mat img=cv::imread(path);   
	cv::imshow("Frame",img);            
	cv::waitKey(5000);               

	*/




	cv::Mat img;

	cv::VideoCapture cam(0);  

	std::vector<cv::Rect>faces_coord;  

	cv::CascadeClassifier facedetecter;

	facedetecter.load("haarcascade_frontalface_default.xml");     //Open Source Computer Vision Library



	while (1)
	{
		cam.read(img);

		facedetecter.detectMultiScale(img, faces_coord, 1.3, 5);   

		for (int i = 0; i < faces_coord.size(); i++)
		{
			cv::rectangle(img, faces_coord[i], cv::Scalar(250, 0, 0), 3);  

			cv::rectangle(img, cv::Point(15, 20), cv::Point(260, 60), cv::Scalar(90,35 , 200), cv::FILLED);  

			cv::putText(img, std::to_string(faces_coord.size()) + " Face Found", cv::Point(25, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);
		}

		cv::imshow("VideoFrame", img);

		cv::waitKey(1);
	}





	return 0;
}




