import os
import json

# Root Projects folder
projects_dir = "Projects"

# Default JSON fields
default_description = "This project showcases technical skills and applied knowledge in engineering, electronics, and software development."
default_tech = ["ESP32", "Raspberry Pi", "Python", "Other relevant tech"]
default_status = "Completed"

# Ensure Projects folder exists
os.makedirs(projects_dir, exist_ok=True)

# Scan all subfolders dynamically
for project_name in os.listdir(projects_dir):
    project_path = os.path.join(projects_dir, project_name)
    if os.path.isdir(project_path):
        json_path = os.path.join(project_path, f"{project_name}.json")
        print(json_path)

        # Load existing JSON if it exists
        if os.path.exists(json_path):
            print('maiii bhonndu huu')
            with open(json_path, "r") as f:
                project_data = json.load(f)
                
        else:
            print('so far so good')
            project_data = {}

        # Update JSON fields
        project_data["name"] = project_name
        project_data["description"] = project_data.get("description", default_description)
        project_data["tech"] = project_data.get("tech", default_tech)
        project_data["status"] = project_data.get("status", default_status)

        # Write JSON
        print('creatings JSON file I hope')
        with open(json_path, "w") as f:
            json.dump(project_data, f, indent=4)

print("Project JSONs created/updated successfully!")
