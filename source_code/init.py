import seaborn as sns
import matplotlib.pyplot as plt
import plotly as py
import pandas as pd
import math

def gather_user_pref():

    print("AltiusVista setup")

    preferred_plot_type = input("Input the plot type that you would like to use (e.g., line, bar, scatter): ")
    
    user_preferences = {
        "plot_type": preferred_plot_type
    }
    
    print(f"Your preferences have been saved.")

    return user_preferences

gather_user_pref()