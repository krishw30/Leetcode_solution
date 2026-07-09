import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    # 1. Get unique salaries and sort them in descending order
    unique_salaries = employee['salary'].drop_duplicates().sort_values(ascending=False)
    
    # 2. Check if a second highest salary exists
    if len(unique_salaries) < 2:
        second_highest = None
    else:
        # Use .iloc[1] to safely get the second item by position
        second_highest = unique_salaries.iloc[1]
        
    # 3. Return the result as a DataFrame with the requested column name
    return pd.DataFrame({'SecondHighestSalary': [second_highest]})

