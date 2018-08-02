//
//  sample.hpp
//  
//
//  Created by x16043xx on 2018/07/11.
//
//
// #ifndef、#define、#endifマクロで二重インクルードの防止処理が施されています。
#ifndef binarization_hpp
#define binarization_hpp

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>  //OpenCV関連ヘッダ

using namespace std;


class Binarization{
public:
    //  コンストラクタ
    Binarization();
    //  デストラクタ
    ~Binarization();
    void deside_para();//パラメーターの決定
    void run_threshold(cv::Mat src_img,cv::Mat *dst_img);//二値化処理の実行
private:
    int technique;//二値化手法(0~13)
    int thresh;//閾値(0~255)
    int block_size;
    //adaptiveThreshold関数に用いる引数
    //閾値計算にしようする近傍領域のサイズ(#define で定義）
    //１より大きい奇数
    int constant;
    //adaptiveThreshold関数に用いる引数
    //減算定数(0~255)
    //文字領域の抽出に使うのに便利
};
#endif  /* data_hpp */
//////////////////////////////////////
//int technique 二値化手法について
// teccnique=0 のとき 関数 cv::threshold
//　　　　　　　　　　　 閾値処理の種類 CV_THRESH_BINARY　（閾値を超えるピクセルは maxValに、それ以外は 0 ）
// teccnique=1 のとき 関数 cv::threshold
//　　　　　　　　　　　 閾値処理の種類 CV_THRESH_BINARY_INV　（閾値を超えるピクセルは 0 に、それ以外は maxVal ）
// teccnique=2 のとき 関数 cv::threshold
//　　　　　　　　　　　 閾値処理の種類 CV_THRESH_TRUNC　（閾値を超えるピクセルは thresh に、それ以外は maxVal ）
// teccnique=3 のとき 関数 cv::threshold
//　　　　　　　　　　　 閾値処理の種類 CV_THRESH_TOZERO　（閾値を超えるピクセルは変更されない。それ以外は 0  ）
// teccnique=4 のとき 関数 cv::threshold
//　　　　　　　　　　　 閾値処理の種類 CV_THRESH_TOZERO_INV　（閾値を超えるピクセルは 0 に、それ以外は変更されない）
// teccnique=5 のとき 関数 cv::threshold
//　　　　　　　　　　　 閾値処理の種類 CV_THRESH_BINARY | CV_THRESH_OTSU　（最適な閾値を自動で決定し、CV_THRESH_BINARYと同様）
// teccnique=6 のとき 関数 cv::threshold
//　　　　　　　　　　　 閾値処理の種類 CV_THRESH_BINARY_INV | CV_THRESH_OTSU　（最適な閾値を自動で決定し、CV_THRESH_BINARY_INVと同様）
// teccnique=7 のとき 関数 cv::threshold
//　　　　　　　　　　　 閾値処理の種類 CV_THRESH_TRUNC | CV_THRESH_OTSU　（最適な閾値を自動で決定し、CV_THRESH_TRUNCと同様）
// teccnique=8 のとき 関数 cv::threshold
//　　　　　　　　　　　 閾値処理の種類 CV_THRESH_TOZERO | CV_THRESH_OTSU　（最適な閾値を自動で決定し、CV_THRESH_TOZEROと同様）
// teccnique=9 のとき 関数 cv::threshold
//　　　　　　　　　　　 閾値処理の種類 CV_THRESH_TOZERO_INV | CV_THRESH_OTSU　(最適な閾値を自動で決定し、CV_THRESH_TOZERO_INVと同様）
// teccnique=10 のとき 関数 cv::adaptiveThreshold
//　　　　　　　　　　　 閾値処理の種類 CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY
// teccnique=11 のとき 関数 cv::adaptiveThreshold
//　　　　　　　　　　　 閾値処理の種類 CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY_INV
// teccnique=12 のとき 関数 cv::adaptiveThreshold
//　　　　　　　　　　　 閾値処理の種類 CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY
// teccnique=13 のとき 関数 cv::adaptiveThreshold
//　　　　　　　　　　　 閾値処理の種類 CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY_INV


