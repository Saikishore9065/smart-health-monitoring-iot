import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, confusion_matrix
import seaborn as sns
import matplotlib.pyplot as plt

# Load dataset
df = pd.read_csv("processed_dataset.csv")

# Extract features and labels
X = df[['BPM', 'SpO2', 'Temp(C)']]
y = df['Condition']

# Convert labels to numeric
y = y.map({'Normal': 1, 'Abnormal': 0})

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# Initialize SVM model
svm_model = SVC(kernel='rbf')

# Train model
svm_model.fit(X_train, y_train)

# Predictions
y_pred = svm_model.predict(X_test)

# Accuracy
accuracy = accuracy_score(y_test, y_pred)
print("SVM Accuracy:", accuracy)

# Confusion matrix
cm = confusion_matrix(y_test, y_pred)
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues')
plt.title("Confusion Matrix")
plt.show()

# Save model accuracy to file
with open("model_accuracy.txt", "w") as f:
    f.write(f"SVM Accuracy: {accuracy}")
