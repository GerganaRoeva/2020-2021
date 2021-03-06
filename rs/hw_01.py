from collections import OrderedDict


def filter_logs(log, key, value):
    new_list = []
    
    for el in log:
        for key_ in el:
            if key == key_:
                if value == el[key_]:
                    new_list.append(el)
                    
    return new_list
    
    
def top(log, key, count):
    values_list = []
    values_dict = {}
    result = {}
    
    for el in log:
        for key_ in el:
            if key_ == key:
                values_list += [el[key]]
                
    for item in values_list:
        if item in values_dict:
            values_dict[item] += 1
        else:
            values_dict[item] = 1
            
    values_dict = OrderedDict(sorted(values_dict.items(), key=lambda x: x[1], reverse=True))
    i = count
    
    for x in values_dict:
        if i > 0:
            result[x] = values_dict[x]
            i -= 1
            
    return result
    
    
def complex_filter(logs, filter_params):
    result = []
    new_dict = {}
    
    for el in logs:
        for key_l in el:
            for key_f in filter_params:
                if key_f == key_l:
                    new_dict[key_l] = el[key_l]
        if new_dict == filter_params:
            result.append(el)
            
    return result
