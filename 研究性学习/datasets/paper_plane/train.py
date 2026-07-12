from ultralytics import YOLO

# 加载预训练模型（n 为 nano，速度快；s 为 small，精度更高）
model = YOLO('yolov8n.pt')  

# 训练
model.train(
    data='paper_plane.yaml',
    epochs=50,          # 训练轮数，可根据效果增减
    imgsz=640,          # 图像尺寸，如果飞机很小可适当调大，如 800
    batch=16,           # 批大小，根据显存调整，CPU 训练可设 4-8
    name='plane_detect' # 实验名称，结果保存在 runs/detect/plane_detect
)
