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

# Scan all items in Projects folder and process only folders
for project_name in os.listdir(projects_dir):
    project_path = os.path.join(projects_dir, project_name)

    # If it's not a folder, skip
    if not os.path.isdir(project_path):
        continue

    # JSON path inside project folder
    json_path = os.path.join(project_path, f"{project_name}.json")

    # Create or update JSON
    try:
        # Load existing JSON if present
        if os.path.exists(json_path):
            with open(json_path, "r") as f:
                project_data = json.load(f)
        else:
            project_data = {}

        # Update fields (without overwriting existing ones)
        project_data["name"] = project_name
        project_data["description"] = project_data.get("description", default_description)
        project_data["tech"] = project_data.get("tech", default_tech)
        project_data["status"] = project_data.get("status", default_status)

        # Write JSON
        with open(json_path, "w") as f:
            json.dump(project_data, f, indent=4)

        print(f"✅ Saved JSON for '{project_name}' at: {os.path.abspath(json_path)}")

    except Exception as e:
        print(f"❌ Failed to save JSON for '{project_name}': {e}")

# Handle the case when Projects folder is empty
if not os.listdir(projects_dir):
    print(f"⚠️ Projects folder is empty. Create subfolders for your projects, and rerun the script.")
