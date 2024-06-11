import mediapipe as mp
import cv2
import shortcuts.arduino as ar

mp_hands = mp.solutions.hands
hands = mp_hands.Hands()
mp_drawing = mp.solutions.drawing_utils

ar.isConnected("CH340")

def count_fingers( hand_landmarks):
    finger_tips = [8, 12, 16, 20]  # Index, Middle, Ring, Pinky
    # thumb_tip = 4
    farray=""

    if hand_landmarks.landmark[4].x > hand_landmarks.landmark[2].x:
        farray=farray+'1'
    else:farray=farray+'0'

    for tip in finger_tips:
        if hand_landmarks.landmark[tip].y < hand_landmarks.landmark[tip - 2].y:
            farray=farray+'1'
        else:farray=farray+'0'

    print("Cam: "+farray)
    ar.toArduino(farray)
    print("Received: "+ar.fromArduino())
    

cap = cv2.VideoCapture(0)
while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    frame = cv2.flip(frame, 1)
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    result = hands.process(rgb_frame)

    if result.multi_hand_landmarks:
        for hand_landmarks in result.multi_hand_landmarks:
            count_fingers( hand_landmarks)



    cv2.imshow('Robotic Arm software', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
