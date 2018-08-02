#include <iostream>  //入出力関連ヘッダ
#include <opencv2/opencv.hpp>  //OpenCV関連ヘッダ
#include "binarization.hpp"
#define MAX_SIZE 7
using namespace std;

//  コンストラクタ
extern int parameter[100];
extern int p_num;
extern int p_lust_num;
//void Binarization::set_test(int num){
//    parameter[p_num]=num;
//    p_num++;
//}
void set_test(int num){
    parameter[p_num]=num;
    p_num++;
}
//  コンストラクタ
Binarization::Binarization(){
    //初期設定
    technique=0;
    thresh=0;
    block_size=1;//block_sizeのみ奇数
    constant=0;
}
//  デストラクタ
Binarization::~Binarization() {
    
}

void Binarization::deside_para(){//deside_paraを呼び起こすたびに、新たなparameterをセットする
    p_lust_num=p_num;
    if(technique<=4){//cv::threshold関数を使うとき（パラメータは２つ）
        if(thresh==256){
            thresh=0;
            technique++;
        }
        set_test(technique);
        set_test(thresh);
        thresh++;
        p_num-=2;
        p_lust_num+=2;
    }else if(technique<=9){
        set_test(technique);
        technique++;
        p_num--;
        p_lust_num++;
    }else{//cv::adaptiveThreshold関数を使うとき（パラメータは４つ）
        set_test(technique);
        set_test(thresh);
        set_test(block_size);
        set_test(constant);
        p_num-=4;
        p_lust_num+=4;
        constant++;
    }if(constant==256){//閾値が２５５超えた時
        constant=0;
        block_size+=2;
    }if(block_size==MAX_SIZE+2){
        constant=0;
        block_size=1;
        thresh++;
    }if(thresh==256){
        constant=0;
        block_size=1;
        thresh=0;
        technique++;
    }
}
void Binarization::run_threshold(cv::Mat sourceImage,cv::Mat *dstImage){
    if(parameter[p_num]==0){
        cv::threshold(sourceImage, *dstImage, parameter[p_num+1], 255, CV_THRESH_BINARY);
    }if(parameter[p_num]==1){
        cv::threshold(sourceImage, *dstImage, parameter[p_num+1], 255, CV_THRESH_BINARY_INV);
    }if(parameter[p_num]==2){
        cv::threshold(sourceImage, *dstImage, parameter[p_num+1], 255, CV_THRESH_TRUNC);
    }if(parameter[p_num]==3){
        cv::threshold(sourceImage, *dstImage, parameter[p_num+1], 255, CV_THRESH_TOZERO);
    }if(parameter[p_num]==4){
        cv::threshold(sourceImage, *dstImage, parameter[p_num+1], 255, CV_THRESH_TOZERO_INV);
    }if(parameter[p_num]==5){
        cv::threshold(sourceImage, *dstImage, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    }if(parameter[p_num]==6){
        cv::threshold(sourceImage, *dstImage, 0, 255, CV_THRESH_BINARY_INV | CV_THRESH_OTSU);
    }if(parameter[p_num]==7){
        cv::threshold(sourceImage, *dstImage, 0, 255, CV_THRESH_TRUNC | CV_THRESH_OTSU);
    }if(parameter[p_num]==8){
        cv::threshold(sourceImage, *dstImage, 0, 255, CV_THRESH_TOZERO | CV_THRESH_OTSU);
    }if(parameter[p_num]==9){
       cv::threshold(sourceImage, *dstImage, 0, 255, CV_THRESH_TOZERO_INV | CV_THRESH_OTSU);
    }if(parameter[p_num]==10){
         cv::adaptiveThreshold(sourceImage, *dstImage,parameter[p_num+1],CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY,parameter[p_num+2],parameter[p_num+3]);
    }if(parameter[p_num]==11){
        cv::adaptiveThreshold(sourceImage, *dstImage,parameter[p_num+1],CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY_INV,parameter[p_num+2],parameter[p_num+3]);
    }if(parameter[p_num]==12){
        cv::adaptiveThreshold(sourceImage, *dstImage,parameter[p_num+1],CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY,parameter[p_num+2],parameter[p_num+3]);
    }if(parameter[p_num]==13){
        cv::adaptiveThreshold(sourceImage, *dstImage,parameter[p_num+1],CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY_INV,parameter[p_num+2],parameter[p_num+3]);
    }


}
