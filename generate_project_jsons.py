import os
import json

projects_dir = "Projects"

# Ensure Projects folder exists
os.makedirs(projects_dir, exist_ok=True)

# Default values for new or updated projects
default_description = "This project showcases technical skills and applied knowledge in engineering, electronics, and software development."
default_tech = ["ESP32", "Raspberry Pi", "Python", "Other relevant tech"]
default_status = "Completed"

for project_name in os.listdir(projects_dir):
    project_path = os.path.join(projects_dir, project_name)
    if os.path.isdir(project_path):
        json_path = os.path.join(project_path, f"{project_name}.json")
        
        # If JSON exists, load it; otherwise, create a new dictionary
        if os.path.exists(json_path):
            with open(json_path, "r") as f:
                project_data = json.load(f)
        else:
            project_data = {}

        # Update or set the default fields
        project_data["name"] = project_name
        project_data["description"] = project_data.get("description", default_description)
        project_data["tech"] = project_data.get("tech", default_tech)
        project_data["status"] = project_data.get("status", default_status)

        # Write back to JSON
        with open(json_path, "w") as f:
            json.dump(project_data, f, indent=4)

print("Project JSONs created/updated successfully!")
