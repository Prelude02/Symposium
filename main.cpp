//
//  main.cpp
//  
//
//  Created by x16043xx on 2018/07/11.
//
//

#include <iostream>
#include "binarization.hpp"
#include <opencv2/opencv.hpp>  //OpenCV関連ヘッダ
//#include "create_parameter.hpp"
using namespace std;

int process[1000];//処理手順格納用配列
int parameter[1000];//パラメータ格納用配列
int p_num=0;
int p_lust_num=0;
void check_sub(cv::Mat resultImage,cv::Mat idealImage,int *fitness,int *para,int *best_para,int lust){//理想画像との差分を求める関数
    cv::Mat subImage;//差分保存用の配列
    cv::absdiff(binImage,idealImage,subImage);//各画素ごとに差分をとって、subImageに保存
    int s=cv::sum(subImage)[0];//subImageの画素値の全ての和
    if(s<*fitness){
        *fitness=s;
        memcpy(*para, *best_para, sizeof(int) * lust);
    }
}

int main(){
    cv::Mat sourceImage = cv::imread("/Users/x16043xx/Desktop/シンポジウム/２値化/20170904142000.jpg", cv::IMREAD_GRAYSCALE);
    if (sourceImage.data==0) {  //画像ファイルが読み込めなかった場合
        printf("File not found\n");
        exit(0);
    }
    cv::Mat idealImage = cv::imread("/Users/x16043xx/Desktop/シンポジウム/２値化/20170904142000.jpg", cv::IMREAD_GRAYSCALE);
    if (sourceImage.data==0) {  //画像ファイルが読み込めなかった場合
        printf("File not found\n");
        exit(0);
    }
    //②画像格納用インスタンスの生成
    cv::Mat resultImage;
    int best_parameter[1000];
    int best_process[1000];
    int fitness=sourceImage.width*sourceImage.height;
    //③ウィンドウの生成と移動
    cv::namedWindow("Source");
    cv::moveWindow("Source", 0,0);
    cv::namedWindow("Result");
    cv::moveWindow("Result", 400,0);

    //④画像処理
    Binarization b1;//二値化
    for(int i=0;i<100200;i++){
    b1.deside_para();
    }
    b1.run_threshold(sourceImage,&resultImage);
    cout<<parameter[0]<<endl;
    cout<<parameter[1]<<endl;
    cout<<parameter[2]<<endl;
    cout<<parameter[3]<<endl;
    cout<<parameter[4]<<endl;
    cout<<parameter[5]<<endl;
    cout<<parameter[6]<<endl;
    cout<<parameter[7]<<endl;

    
    
    //⑤ウィンドウへの画像の表示
    cv::imshow("Source", sourceImage);
    cv::imshow("Result", resultImage);
    
    //⑥キー入力待ち
    cv::waitKey(0);

    
    return 0;
}
