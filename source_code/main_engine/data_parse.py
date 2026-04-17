import json

def gather_data():
    try:
        
        with open("save_data.json", "r") as save_data:

            data = json.load(save_data)

    except json.JSONDecodeError:

        print("Error reading saved data. Starting fresh.")
        return None


    return data

data_parse_que = gather_data()
parsed_data = []

def append_data():
    for i in data_parse_que:

        if isinstance(i, str):

            parsed_data.append(i)

        elif isinstance(i, list):

            parsed_data.append([float(x) for x in i])

        else:

            print(f"Unsupported data type: {type(i)}. Skipping.")
        
    return parsed_data

append_data()
