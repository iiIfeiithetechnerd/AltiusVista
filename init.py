import json

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

    x_data = input("Input the data for your x-axis: ")
    y_data = input("Input the data for your y-axis: ")

    user_preferences = {

        "plot_type": preferred_plot_type,
        "dimension_type": preferred_dimension_type,
        "color": preferred_color,
        "title": main_title,
        "x-label": x_axis_label,
        "y-label": y_axis_label,
        "x-data": x_data,
        "y-data": y_data
    }

    save_data = (json.dumps(user_preferences), json.dumps(graph_data))

    f = open("save_data.json", "w")
    json.dump(save_data, f)
    f.close()

    print(f"Your preferences, titles, and data has been saved.")
    return user_preferences, graph_data

gather_user_pref()