import cv2
import numpy as np
import matplotlib.pyplot as plt

# 读取你的照片
image_path = 'me.jpg'  # 替换成你的照片路径
image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
image = image / 255.0  # 将图像归一化到 [0, 1] 范围

# 定义对数变换函数
def log_transform(image, c=1):
    return c * np.log(1 + image)

# 进行对数变换
c = 1
log_image = log_transform(image, c)

# 归一化到 [0, 1] 范围
log_image = cv2.normalize(log_image, None, 0, 1, cv2.NORM_MINMAX)

# 创建子图
fig, axes = plt.subplots(1, 2, figsize=(10, 5))
axes = axes.ravel()

# 显示原图和对数变换后的图像
axes[0].imshow(image, cmap='gray')
axes[0].set_title('Original Image')
axes[0].axis('off')

axes[1].imshow(log_image, cmap='gray')
axes[1].set_title('Log Transformed Image')
axes[1].axis('off')

plt.tight_layout()
plt.show()

