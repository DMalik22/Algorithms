# Uses python3
import sys

def get_optimal_value(capacity, weights, values):
    value = 0.
    ratios = {}

    for i in range(len(weights)):
      if weights[i] is not 0:
        ratios[float(values[i])/float(weights[i])] = i

    list_of_values = sorted(ratios.keys())
    #print(list_of_values)
    number_of_items_left = len(list_of_values)

    if number_of_items_left is 0:
        return value

    while (capacity > 0):
        number_of_items_left = number_of_items_left - 1

        val_to_weight_ratio = list_of_values.pop()
        obj_num = ratios[val_to_weight_ratio]
        w = weights[i]
        v = values[i]
        if (w < capacity):
            capacity = capacity - w
            value = value + v
        else:
            value = value + (val_to_weight_ratio * capacity)
            return value

        if number_of_items_left is 0:
            return value
    return value

if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.9f}".format(opt_value))
