import math
import matplotlib.pyplot as plt

Mu = 4
Lambda = 3
Cw = 20
Cs = 15
n = 1

def sum(m):
    result = 0;
    for n in range(0, m):
        result += ((1/(math.factorial(n))) * (Lambda / Mu) ** n)
    return result

def Po(m) :
    # print(sum(m))
    Po = 1 / ((sum(m)) + (1/(math.factorial(m))) * ((Lambda / Mu) ** m) * ((m * Mu) / (m * Mu - Lambda)))
    return Po

y_axis_waiting_cost = []
x_axis_waiting_cost  = []

y_axis_service_cost = []
x_axis_service_cost  = []

y_axis_cost = []
x_axis_cost = []


for i in range(1, 10) :
    x_axis_waiting_cost.append(i)
    x_axis_service_cost.append(i)
    x_axis_cost.append(i)

for m in range(1, 10) :
    Wq = ((Mu * (Lambda / Mu) ** m) * Po(m)) / (math.factorial(m - 1) * (m * Mu - Lambda) ** 2)
    Total_Waiting_Cost = n * 3 * Wq * Cw
    Total_Service_Cost = n * m * Cs
    print(f"m = {m} \t| Wq : {Wq} \t| Po : {Po(m)} \t| Ts : {round(Total_Service_Cost,3)} \t|Tw :{round(Total_Waiting_Cost,3)} \t| T: {round(Total_Service_Cost + Total_Waiting_Cost,3)}")
    y_axis_waiting_cost.append(Total_Waiting_Cost)
    y_axis_service_cost.append(Total_Service_Cost)
    y_axis_cost.append(Total_Service_Cost + Total_Waiting_Cost)
    


print("Total Waiting Cost Graph")
p1 = plt.plot(x_axis_waiting_cost, y_axis_waiting_cost)
p1 = plt.title("Total Waiting Cost Graph")
plt.show(p1)

print("Total Service Cost Graph")
p2 = plt.plot(x_axis_service_cost, y_axis_service_cost)
p2 = plt.title("Total Service Cost Graph")
plt.show(p2)
    
print("Total Service Cost Graph")
p3 = plt.plot(x_axis_cost, y_axis_cost)
p3 = plt.title("Total Cost Graph")
plt.show(p3)