import cv2 as cv


def gaussian_pyramid(image):
    level = 3
    temp = image.copy()  
    gaussian_images = []  
    for i in range(level):
        dst = cv.pyrDown(temp)   
        gaussian_images.append(dst)  
        cv.imshow("gaussian"+str(i), dst)
        temp = dst.copy()
    return gaussian_images


def laplacian_pyramid(image):
    resize_image = cv.resize(image, (560, 560))
    gaussian_images = gaussian_pyramid(resize_image)    
    level = len(gaussian_images)
    for i in range(level-1, -1, -1):
        if (i-1) < 0:
            expand = cv.pyrUp(gaussian_images[i], dstsize = resize_image.shape[:2])
            laplacian = cv.subtract(resize_image, expand)   
            cv.imshow("laplacian_down_"+str(i), laplacian)
        else:
            expand = cv.pyrUp(gaussian_images[i], dstsize = gaussian_images[i-1].shape[:2])
            laplacian = cv.subtract(gaussian_images[i-1], expand)            
            cv.imshow("laplacian_down_"+str(i), laplacian)


src = cv.imread(r'D:\Desktop\1A.jpg')
print(src.shape)
# input_image = cv.resize(src, (560, 560)) 
cv.namedWindow('input_image', cv.WINDOW_AUTOSIZE)
cv.imshow('input_image', src)
laplacian_pyramid(src)
cv.waitKey(0)
cv.destroyAllWindows()
