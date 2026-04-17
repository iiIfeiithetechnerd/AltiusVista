import json
import subprocess
import sys
import os

def check_data_collected():

    if os.path.isfile("save_data.json"):

        try:

            with open("save_data.json", "r") as save_data:

                data = json.load(save_data)

                if isinstance(data, dict) and data.get("Data-gathered") == True:

                    get_answer = input("Would you like to use the existing dataset? y/n: ")

                    if get_answer.lower() == "y":

                        return data
                    
                    elif get_answer.lower() == "n":

                        return None
                    
                    else:

                        print("Invalid input. Assuming no.")
                        return None
                    
        except json.JSONDecodeError:

            print("Error reading saved data. Starting fresh.")
            return None
        
    return None


def gather_user_pref():

    print("AltiusVista setup")
    valid_plot_types = ['line', 'bar', 'scatter', 'hist']

    while True:
        preferred_plot_type = input("Input the plot type that you would like to use (line, bar, scatter, hist): ").strip().lower()

        if preferred_plot_type in valid_plot_types:

            break

        print("Invalid plot type. Please choose from: line, bar, scatter, hist.")

    valid_dimensions = ['2d', '3d']
    while True:

        preferred_dimension_type = input("Input the dimension type that you would like to use (2D, 3D): ").strip().lower()

        if preferred_dimension_type in valid_dimensions:

            break

        print("Invalid dimension. Please choose 2D or 3D.")

    valid_colors = ['rgba', 'hex']

    while True:
        
        prompt = f"Input the color format you would like to use ({', '.join(valid_colors).title()}): "
        preferred_color = input(prompt).strip().lower()

        if preferred_color in valid_colors:
            break
        
        
        print(f"Invalid format '{preferred_color}'. Please choose from: {', '.join(valid_colors)}.")


    print("Graph titles")

    main_title = input("Input your title for this graph: ").strip()
    x_axis_label = input("Input your x-axis label: ").strip()
    y_axis_label = input("Input your y-axis label: ").strip()

    print("Graph data")

    while True:

        x_data_str = input("Input the data for your x-axis (comma-separated numbers): ").strip()

        try:
            x_data = [float(x.strip()) for x in x_data_str.split(',') if x.strip()]

            if x_data:
                break
            else:

                print("No valid numbers entered. Please try again.")

        except ValueError:

            print("Invalid input. Please enter comma-separated numbers.")

    while True:

        y_data_str = input("Input the data for your y-axis (comma-separated numbers): ").strip()

        try:

            y_data = [float(y.strip()) for y in y_data_str.split(',') if y.strip()]
            if y_data:

                break

            else:

                print("No valid numbers entered. Please try again.")

        except ValueError:

            print("Invalid input. Please enter comma-separated numbers.")

    data_gathered = True

    user_preferences = {

        "plot_type": preferred_plot_type,
        "dimension_type": preferred_dimension_type,
        "color": preferred_color,
        "title": main_title,
        "x-label": x_axis_label,
        "y-label": y_axis_label,
        "x-data": x_data,
        "y-data": y_data,
        "Data-gathered": data_gathered

    }

    try:

        with open("save_data.json", "w") as f:
            json.dump(user_preferences, f, indent=4)
        print("Your preferences, titles, and data have been saved.")

    except IOError as e:

        print(f"Error saving data: {e}")

    return user_preferences

data = check_data_collected()
if data is None:

    data = gather_user_pref()

subprocess.run([sys.executable, "main_engine/data_parse.py"])