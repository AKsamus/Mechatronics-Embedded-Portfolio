import os
import json

PROJECTS_DIR = "Projects"

# Make sure Projects folder exists
os.makedirs(PROJECTS_DIR, exist_ok=True)

for folder_name in os.listdir(PROJECTS_DIR):
    folder_path = os.path.join(PROJECTS_DIR, folder_name)
    
    if os.path.isdir(folder_path):
        json_path = os.path.join(PROJECTS_DIR, f"{folder_name}.json")
        meta_path = os.path.join(folder_path, "meta.json")
        
        # Try to read meta.json if exists
        if os.path.exists(meta_path):
            with open(meta_path, "r", encoding="utf-8") as f:
                meta = json.load(f)
        else:
            # If no meta.json, create basic info from folder name
            meta = {
                "title": folder_name.replace("-", " "),
                "description": "Description not provided yet",
                "technologies": []
            }

        # Write JSON file in Projects folder
        with open(json_path, "w", encoding="utf-8") as f:
            json.dump(meta, f, indent=4)
        
        print(f"Generated {json_path}")

print("Project JSON generation complete!")
