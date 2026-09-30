# Smart Health Monitoring System Using IoT Technology

This project is an IoT‑based real‑time health monitoring system that captures physiological parameters such as **body temperature**, **heart rate**, and **SpO₂** using Arduino‑based sensors. The collected data is stored, processed, and analyzed using machine learning—specifically the **Support Vector Machine (SVM)** algorithm—to classify patient conditions as **Normal** or **Abnormal**.

## 🔧 Hardware Components
- Arduino UNO R3  
- DS18B20 Temperature Sensor  
- MAX30100 Pulse Oximeter & Heart Rate Sensor  
- Jumper wires, breadboard  

## 📡 Data Collection
Sensor readings are captured through Arduino and logged into a CSV file using the **ArduSpreadsheet** extension.

Example data:
- BPM  
- SpO₂  
- Temperature (°C)  
- Condition (Normal/Abnormal)  

## 🤖 Machine Learning Model
The dataset is processed using:
- Support Vector Machine (SVM)
- Random Forest
- Decision Tree
- Naive Bayes

SVM achieved the highest accuracy: **96.72%**

## 📈 Features
- Real‑time physiological monitoring  
- Automatic CSV logging  
- ML‑based prediction of patient condition  
- Visualization using heatmaps, boxplots, and accuracy graphs  

## 🧪 Project Workflow
1. Connect sensors to Arduino  
2. Capture real‑time data  
3. Store data in CSV  
4. Train ML model  
5. Predict Normal/Abnormal  
6. Visualize results  

## 👤 Author
**Sai Kishore Adapaka**  
M.S. Information Systems, University of Memphis
