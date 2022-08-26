# Color-texture-detection
This repo is for color and texture
## 图像金字塔:
## ①高斯金字塔：用于下采样。高斯金字塔是最基本的图像塔。
  原理：首先将原图像作为最底层图像G0（高斯金字塔的第0层），利用高斯核（5*5）对其进行卷积，然后对卷积后的图像进行下采样（去除偶数行和列）得到上一层图像G1，
  将此图像作为输入，重复卷积和下采样操作得到更上一层图像，反复迭代多次，形成一个金字塔形的图像数据结构，即高斯金字塔。

 ## ②拉普拉斯金字塔：用于重建图像，也就是预测残差，对图像进行最大程度的还原。比如一幅小图像重建为一幅大图，
  原理：用高斯金字塔的每一层图像减去其上一层图像上采样并高斯卷积之后的预测图像，得到一系列的差值图像即为 LP 分解图像。

 ## ①上采样：就是图片放大（所谓上嘛，就是变大），使用PryUp函数。
  上采样步骤：先将图像在每个方向放大为原来的两倍，新增的行和列用0填充，再使用先前同样的内核与放大后的图像卷积，获得新增像素的近似值。
 ## ②下采样：就是图片缩小（所谓下嘛，就是变小），使用PryDown函数。下采样将步骤：先对图像进行高斯内核卷积 ，再将所有偶数行和列去除。
  总之，上、下采样都存在一个严重的问题，那就是图像变模糊了，因为缩放的过程中发生了信息丢失的问题。要解决这个问题，就得用拉普拉斯金字塔。
