import cv2
import numpy as np
import matplotlib.pyplot as plt

# 读取你的照片
image_path = 'dim.png'  # 替换成你的照片路径
image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
image = image / 255.0  # 将图像归一化到 [0, 1] 范围

# 定义幂次变换（伽马变换）函数
def gamma_transform(image, c, gamma):
    return c * np.power(image, gamma)

# 定义不同的参数
params = [
    (1, 0.5),  # 增强暗部细节
    (1, 1.0),  # 线性变换
    (1, 2.0),  # 增强亮部细节
    (0.5, 0.5),  # 增强暗部细节，降低亮度
    (2.0, 2.0)  # 增强亮部细节，提高亮度
]

# 创建子图
fig, axes = plt.subplots(2, 3, figsize=(15, 10))
axes = axes.ravel()

# 显示原图
axes[0].imshow(image, cmap='gray')
axes[0].set_title('Original Image')
axes[0].axis('off')

# 显示不同参数下的幂次变换后的图像
for ax, (c, gamma) in zip(axes[1:], params):
    transformed_image = gamma_transform(image, c, gamma)
    transformed_image = np.clip(transformed_image, 0, 1)  # 确保像素值在 [0, 1] 范围内
    ax.imshow(transformed_image, cmap='gray')
    ax.set_title(f'c={c}, γ={gamma}')
    ax.axis('off')

# 隐藏多余的子图框
for ax in axes[len(params) + 1:]:
    ax.axis('off')

plt.tight_layout()
plt.show()

