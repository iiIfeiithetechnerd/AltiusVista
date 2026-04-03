import seaborn as sns
import matplotlib.pyplot as plt
import plotly as py
import pandas as pd
import math

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
        "y-data": y_data
    }
    
    print(f"Your preferences, titles, and data has been saved.")

    return user_preferences

gather_user_pref()