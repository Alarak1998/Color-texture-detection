import numpy as np
import pywt
import cv2
import matplotlib.pyplot as plt
 
 
def haar_img():
    img_u8 = cv2.imread(r"D:\Desktop\spot1.png")
    img_f32 = cv2.cvtColor(img_u8, cv2.COLOR_BGR2GRAY).astype(np.float32)
 
    plt.figure('二维小波一级变换')
    coeffs = pywt.dwt2(img_f32, 'haar')
    cA, (cH, cV, cD) = coeffs
 
    plt.imshow(cH, 'gray')
    # plt.imsave('cH.png', cH, cmap='gray')
    cv2.imshow('cH', cH)

    plt.imshow(cA, 'gray')
    # plt.imsave('cA.png', cA, cmap='gray')
    cv2.imshow('cA', cA)

    plt.imshow(cV, 'gray')
    # plt.imsave('cV.png', cV, cmap='gray')
    cv2.imshow('cV', cV)

    plt.imshow(cD, 'gray')
    # plt.imsave('cD.png', cD, cmap='gray')
    cv2.imshow('cD', cD)
    cv2.waitKey()
    # 将各个子图进行拼接，最后得到一张图
    # AH = np.concatenate([cA, cH], axis=1)
    # VD = np.concatenate([cV, cD], axis=1)
    # img = np.concatenate([AH, VD], axis=0)
    # return img
 
if __name__ == '__main__':
    haar_img()