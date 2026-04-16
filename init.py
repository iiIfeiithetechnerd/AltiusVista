import json
import subprocess
import sys

def check_data_collected():
    with open("save_data.json", "r") as save_data:
        
        data = json.load(save_data)
        return data

    if (data["Data-gathered"] == "True"):
        
        get_answer = input("Would you like to create a new dataset? Y/n ")
        
        if (get_answer == "y" | get_answer == "Y"):
            
            gather_user_pref()
            
        elif (get_answer == "n" | get_answer =="N"):
            
            sys.exit()
        
def gather_user_pref():

    print("AltiusVista setup")

    preferred_plot_type = input("Input the plot type that you would like to use (e.g., line, bar, scatter, hist): ")
    preferred_dem_type = input("Input the demension type that you would like to use (e.g. 2D, 2.5D, 3D...): ")
    preferred_color = input("Input the color that you would like to use (RGBA, Hex): ")

    print("Graph titles")

    main_title = input("Input your title for this graph: ")
    x_axi_label = input("Input your x-axis label: ")
    y_axi_label = input("Input your y-axis label: ")

    print("Graph data")

    x_data = input("Input the data for your x-axis: ")
    y_data = input("Input the data for your y-axis: ")
    data_gathered = True

    user_preferences = {
        "plot_type": preferred_plot_type,
        "dem_type": preferred_dem_type,
        "color": preferred_color,
        "title": main_title,
        "x-label": x_axi_label,
        "y-label": y_axi_label
    }

    graph_data = {
        "x-data": x_data,
        "y-data": y_data,
        "Data-gathered": data_gathered
    }

    save_data = (json.dumps(user_preferences), json.dumps(graph_data))

    f = open("save_data.json", "w")
    json.dump(save_data, f)
    f.close()

    print(f"Your preferences, titles, and data has been saved.")
    return user_preferences, graph_data

check_data_collected()
gather_user_pref()
subprocess.run([sys.executable, "main_engine/data_parse.py"])
