import numpy as np

training_data = [
  [6.3, 3.3, 6.0, 2.5],                                                      
  [5.8, 2.7, 5.1, 1.9],                                                      
  [7.1, 3.0, 5.9, 2.1],                                                      
  [6.3, 2.9, 5.6, 1.8],                                                      
  [6.5, 3.0, 5.8, 2.2],                                                      
  [7.6, 3.0, 6.6, 2.1],                                                      
  [4.9, 2.5, 4.5, 1.7],                                                      
  [7.3, 2.9, 6.3, 1.8],                                                      
  [6.7, 2.5, 5.8, 1.8],                                                      
  [7.2, 3.6, 6.1, 2.5],                                                      
  [6.5, 3.2, 5.1, 2.0],                                                      
  [6.4, 2.7, 5.3, 1.9],                                                      
  [6.8, 3.0, 5.5, 2.1],                                                      
  [5.7, 2.5, 5.0, 2.0],                                                      
  [5.8, 2.8, 5.1, 2.4],                                                      
  [6.4, 3.2, 5.3, 2.3],                                                      
  [6.5, 3.0, 5.5, 1.8],                                                      
  [7.7, 3.8, 6.7, 2.2],                                                      
  [7.7, 2.6, 6.9, 2.3],                                                      
  [6.0, 2.2, 5.0, 1.5],                                                      
  [6.9, 3.2, 5.7, 2.3],                                                      
  [5.6, 2.8, 4.9, 2.0],                                                      
  [7.7, 2.8, 6.7, 2.0],                                                      
  [6.3, 2.7, 4.9, 1.8],                                                      
  [6.7, 3.3, 5.7, 2.1],                                                      
  [7.0, 3.2, 4.7, 1.4],                                                      
  [6.4, 3.2, 4.5, 1.5],                                                      
  [6.9, 3.1, 4.9, 1.5],                                                      
  [5.5, 2.3, 4.0, 1.3],                                                      
  [6.5, 2.8, 4.6, 1.5],                                                      
  [5.7, 2.8, 4.5, 1.3],                                                      
  [6.3, 3.3, 4.7, 1.6],                                                      
  [4.9, 2.4, 3.3, 1.0],                                                      
  [6.6, 2.9, 4.6, 1.3],                                                      
  [5.2, 2.7, 3.9, 1.4],                                                      
  [5.0, 2.0, 3.5, 1.0],                                                      
  [5.9, 3.0, 4.2, 1.5],                                                      
  [6.0, 2.2, 4.0, 1.0],                                                      
  [6.1, 2.9, 4.7, 1.4],                                                      
  [5.6, 2.9, 3.6, 1.3],                                                      
  [6.7, 3.1, 4.4, 1.4],                                                      
  [5.6, 3.0, 4.5, 1.5],                                                      
  [5.8, 2.7, 4.1, 1.0],                                                      
  [6.2, 2.2, 4.5, 1.5],                                                      
  [5.6, 2.5, 3.9, 1.1],                                                      
  [5.9, 3.2, 4.8, 1.8],                                                      
  [6.1, 2.8, 4.0, 1.3],                                                      
  [6.3, 2.5, 4.9, 1.5],                                                      
  [6.1, 2.8, 4.7, 1.2],                                                      
  [6.4, 2.9, 4.3, 1.3],                                                      
  [5.1, 3.5, 1.4, 0.2],                                                      
  [4.9, 3.0, 1.4, 0.2],                                                      
  [4.7, 3.2, 1.3, 0.2],                                                      
  [4.6, 3.1, 1.5, 0.2],                                                      
  [5.0, 3.6, 1.4, 0.2],                                                      
  [5.4, 3.9, 1.7, 0.4],                                                      
  [4.6, 3.4, 1.4, 0.3],                                                      
  [5.0, 3.4, 1.5, 0.2],                                                      
  [4.4, 2.9, 1.4, 0.2],                                                      
  [4.9, 3.1, 1.5, 0.1],                                                      
  [5.4, 3.7, 1.5, 0.2],                                                      
  [4.8, 3.4, 1.6, 0.2],                                                      
  [4.8, 3.0, 1.4, 0.1],                                                      
  [4.3, 3.0, 1.1, 0.1],                                                      
  [5.8, 4.0, 1.2, 0.2],                                                      
  [5.7, 4.4, 1.5, 0.4],                                                      
  [5.4, 3.9, 1.3, 0.4],                                                      
  [5.1, 3.5, 1.4, 0.3],                                                      
  [5.7, 3.8, 1.7, 0.3],                                                      
  [5.1, 3.8, 1.5, 0.3],                                                      
  [5.4, 3.4, 1.7, 0.2],                                                      
  [5.1, 3.7, 1.5, 0.4],                                                      
  [4.6, 3.6, 1.0, 0.2],                                                      
  [5.1, 3.3, 1.7, 0.5],                                                      
  [4.8, 3.4, 1.9, 0.2], 
]

testing_data = [
  [7.2, 3.2, 6.0, 1.8],
  [6.2, 2.8, 4.8, 1.8],
  [6.1, 3.0, 4.9, 1.8],
  [6.4, 2.8, 5.6, 2.1],
  [7.2, 3.0, 5.8, 1.6],
  [7.4, 2.8, 6.1, 1.9],
  [7.9, 3.8, 6.4, 2.0],
  [6.4, 2.8, 5.6, 2.2],
  [6.3, 2.8, 5.1, 1.5],
  [6.1, 2.6, 5.6, 1.4],
  [7.7, 3.0, 6.1, 2.3],                                                     
  [6.3, 3.4, 5.6, 2.4],                                                     
  [6.4, 3.1, 5.5, 1.8],                                                     
  [6.0, 3.0, 4.8, 1.8],                                                     
  [6.9, 3.1, 5.4, 2.1],                                                     
  [6.7, 3.1, 5.6, 2.4],                                                     
  [6.9, 3.1, 5.1, 2.3],                                                     
  [5.8, 2.7, 5.1, 1.9],                                                     
  [6.8, 3.2, 5.9, 2.3],                                                     
  [6.7, 3.3, 5.7, 2.5],                                                     
  [6.7, 3.0, 5.2, 2.3],                                                     
  [6.3, 2.5, 5.0, 1.9],                                                     
  [6.5, 3.0, 5.2, 2.0],                                                     
  [6.2, 3.4, 5.4, 2.3],                                                     
  [5.9, 3.0, 5.1, 1.8],
  [6.6, 3.0, 4.4, 1.4],                                                     
  [6.8, 2.8, 4.8, 1.4],                                                     
  [6.7, 3.0, 5.0, 1.7],                                                     
  [6.0, 2.9, 4.5, 1.5],                                                     
  [5.7, 2.6, 3.5, 1.0],                                                     
  [5.5, 2.4, 3.8, 1.1],                                                     
  [5.5, 2.4, 3.7, 1.0],                                                     
  [5.8, 2.7, 3.9, 1.2],                                                     
  [6.0, 2.7, 5.1, 1.6],                                                     
  [5.4, 3.0, 4.5, 1.5],                                                     
  [6.0, 3.4, 4.5, 1.6],                                                     
  [6.7, 3.1, 4.7, 1.5],                                                     
  [6.3, 2.3, 4.4, 1.3],                                                     
  [5.6, 3.0, 4.1, 1.3],                                                     
  [5.5, 2.5, 4.0, 1.3],                                                     
  [5.5, 2.6, 4.4, 1.2],                                                     
  [6.1, 3.0, 4.6, 1.4],                                                     
  [5.8, 2.6, 4.0, 1.2],                                                     
  [5.0, 2.3, 3.3, 1.0],                                                     
  [5.6, 2.7, 4.2, 1.3],                                                     
  [5.7, 3.0, 4.2, 1.2],                                                     
  [5.7, 2.9, 4.2, 1.3],                                                     
  [6.2, 2.9, 4.3, 1.3],                                                     
  [5.1, 2.5, 3.0, 1.1],                                                     
  [5.7, 2.8, 4.1, 1.3],      
  [5.0, 3.0, 1.6, 0.2],                                                     
  [5.0, 3.4, 1.6, 0.4],                                                     
  [5.2, 3.5, 1.5, 0.2],                                                     
  [5.2, 3.4, 1.4, 0.2],                                                     
  [4.7, 3.2, 1.6, 0.2],                                                     
  [4.8, 3.1, 1.6, 0.2],                                                     
  [5.4, 3.4, 1.5, 0.4],                                                     
  [5.2, 4.1, 1.5, 0.1],                                                     
  [5.5, 4.2, 1.4, 0.2],                                                     
  [4.9, 3.1, 1.5, 0.2],                                                     
  [5.0, 3.2, 1.2, 0.2],                                                     
  [5.5, 3.5, 1.3, 0.2],                                                     
  [4.9, 3.6, 1.4, 0.1],                                                     
  [4.4, 3.0, 1.3, 0.2],                                                     
  [5.1, 3.4, 1.5, 0.2],                                                     
  [5.0, 3.5, 1.3, 0.3],                                                     
  [4.5, 2.3, 1.3, 0.3],                                                     
  [4.4, 3.2, 1.3, 0.2],                                                     
  [5.0, 3.5, 1.6, 0.6],                                                     
  [5.1, 3.8, 1.9, 0.4],                                                     
  [4.8, 3.0, 1.4, 0.3],                                                     
  [5.1, 3.8, 1.6, 0.2],                                                     
  [4.6, 3.2, 1.4, 0.2],                                                     
  [5.3, 3.7, 1.5, 0.2],                                                     
  [5.0, 3.3, 1.4, 0.2],
]


V = np.random.rand(2, 4)
W = np.random.rand(3, 2)

# 초기에 랜덤으로 잡아둔 연결강도 값을 유지 시키기 위한 변수
V0 = V
W0 = W

# 학습률
learning_rate = 0.7

# 목표치
target = [
  [1, 0, 0],
  [0, 1, 0],
  [0, 0, 1],
]

# 1개의 데이터 학습이 끝나면 카운트 증가시켜 다음 데이터로 넘어감
x_count = 0
# 25단위로 1씩 증가
class_count = 0


def training(trainig, V, W, learning_rate, target, x_count, class_count):
    E_max = 0.00005
    E_total = 1
    
    for i in range(0, 10000):
        if E_total > E_max:
            def hidden_net(number, x_count, x, V):
                net_hidden = 0
                for i in range(0, 4):
                    net_hidden += x[x_count][i] * V[number - 1][i]
                return net_hidden

            def sigmoid(a):
                y = 1 / (1 + np.exp(-a))
                return y

            def out_net(number, out, W):
                net_output = 0
                for i in range(0, 2):
                    net_output += out[i] * W[number - 1][i]
                return net_output

            def total_err(out_o, class_c, target):
                E_total = 0
                for i in range(0, 3):
                    E_total += (1/2)*(target[class_c][i]-out_o[i])**2
                return E_total

            def update_W(target, class_c, out_o, out_h):
                W_u = [[], [], []]
                W_u[0].append(-(target[class_c][0] - out_o[0]) * out_o[0] * (1 - out_o[0]) * out_h[0])
                W_u[0].append(-(target[class_c][0] - out_o[0]) * out_o[0] * (1 - out_o[0]) * out_h[1])
                W_u[1].append(-(target[class_c][1] - out_o[1]) * out_o[1] * (1 - out_o[1]) * out_h[0])
                W_u[1].append(-(target[class_c][1] - out_o[1]) * out_o[1] * (1 - out_o[1]) * out_h[1])
                W_u[2].append(-(target[class_c][2] - out_o[2]) * out_o[2] * (1 - out_o[2]) * out_h[0])
                W_u[2].append(-(target[class_c][2] - out_o[2]) * out_o[2] * (1 - out_o[2]) * out_h[1])
                return W_u
            
            def update_V(target, class_c, out_o, out_h, x, x_count, W):
                V_u = [[], []]
                for i in range(0, 4):
                    V_u[0].append(((-(target[class_c][0] - out_o[0]) * out_o[0] * (1 - out_o[0]) * W[0][0]) + 
                                    (-(target[class_c][1] - out_o[1])* out_o[1] *(1 - out_o[1]) * W[1][0]) + 
                                    (-(target[class_c][2] - out_o[2])* out_o[2] *(1 - out_o[2]) * W[2][0])) 
                                    * out_h[0] * (1 - out_h[0]) * x[x_count][i])
                    V_u[1].append(((-(target[class_c][0] - out_o[0]) * out_o[0] * (1 - out_o[0]) * W[0][1]) + 
                                    (-(target[class_c][1] - out_o[1])* out_o[1] *(1 - out_o[1]) * W[1][1]) + 
                                    (-(target[class_c][2] - out_o[2])* out_o[2] *(1 - out_o[2]) * W[2][1])) 
                                    * out_h[1] * (1 - out_h[1]) * x[x_count][i])
                return V_u

            def weight_update(learning_rate, V, V_u, W, W_u):
                w_V = [[], []]
                for i in range(0, 2):
                    for j in range(0, 4):
                        w_V[i].append(V[i][j] - (learning_rate * V_u[i][j]))
                w_W = [[], [], []]
                for i in range(0, 3):
                    for j in range(0, 2):
                        w_W[i].append(W[i][j] - (learning_rate * W_u[i][j]))
                return w_V, w_W

            net_h = [hidden_net(1, x_count, trainig, V), hidden_net(2, x_count, trainig, V)]
            out_h = [sigmoid(net_h[0]), sigmoid(net_h[1])]

            net_o = [out_net(1, out_h, W), out_net(2, out_h, W), out_net(3, out_h, W)]
            out_o = [sigmoid(net_o[0]), sigmoid(net_o[1]), sigmoid(net_o[2])]

            E_total = total_err(out_o, class_count, target)

            W_u = update_W(target, class_count, out_o, out_h)
            V_u = update_V(target, class_count, out_o, out_h, trainig, x_count, W)
            V, W = weight_update(learning_rate, V, V_u, W, W_u)
        else:
            break

    x_count += 1
    if x_count == 25 or x_count == 50:
        class_count += 1
    return V, W, x_count, class_count


def testing(testing, x_count, V, W):
    def sigmoid(a):
        y = 1 / (1 + np.exp(-a))
        return y

    def hidden_net(number, x_count, x, V):
        net_hidden = 0
        for i in range(0, 4):
            net_hidden += x[x_count-1][i] * V[number - 1][i]
        return net_hidden

    def out_net(number, out, W):
        net_output = 0
        for i in range(0, 2):
            net_output += out[i] * W[number - 1][i]
        return net_output

    net_h = [hidden_net(1, x_count, testing, V), hidden_net(2, x_count, testing, V)]
    out_h = [sigmoid(net_h[0]), sigmoid(net_h[1])]

    net_o = [out_net(1, out_h, W), out_net(2, out_h, W), out_net(3, out_h, W)]
    out_o = [sigmoid(net_o[0]), sigmoid(net_o[1]), sigmoid(net_o[2])]

    print(x_count, "|", "\tY1: ", round(out_o[0], 6), "\tY2: ", round(out_o[1], 6), "\tY3: ", round(out_o[2], 6))


for i in range(0, 75):
    V, W, x_count, class_count = training(training_data, V0, W0, learning_rate, target, x_count, class_count)
    if x_count == 26 or x_count == 51:
        print("-------------------------------------------------------")
    testing(testing_data, x_count, V, W)
