import seaborn as sns
import matplotlib.pyplot as plt
import plotly as py
import pandas as pd
import math

def gather_user_pref():

    print("AltiusVista setup")

    preferred_plot_type = input("Input the plot type that you would like to use (e.g., line, bar, scatter): ")
    preferred_dem_type = input("Input the demension type that you would like to use (e.g. 2D, 2.5D, 3D...): ")

    user_preferences = {
        "plot_type": preferred_plot_type,
        "dem_type": preferred_dem_type
    }
    
    print(f"Your preferences have been saved.")

    return user_preferences

gather_user_pref()