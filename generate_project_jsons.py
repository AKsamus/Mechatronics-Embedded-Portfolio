from pathlib import Path
import json

# Root Projects folder
projects_dir = Path("Projects")

# Default JSON fields
default_description = "This project showcases technical skills and applied knowledge in engineering, electronics, and software development."
default_tech = ["ESP32", "Raspberry Pi", "Python", "Other relevant tech"]
default_status = "Completed"

# Ensure Projects folder exists
projects_dir.mkdir(parents=True, exist_ok=True)

# Scan all subfolders dynamically
for project_folder in projects_dir.iterdir():
    if not project_folder.is_dir():
        continue

    project_name = project_folder.name
    json_file = project_folder / f"{project_name}.json"

    try:
        # Load existing JSON if it exists
        if json_file.exists():
            project_data = json.loads(json_file.read_text())
        else:
            project_data = {}

        # Update fields without overwriting existing ones
        project_data["name"] = project_name
        project_data["description"] = project_data.get("description", default_description)
        project_data["tech"] = project_data.get("tech", default_tech)
        project_data["status"] = project_data.get("status", default_status)

        # Write JSON
        json_file.write_text(json.dumps(project_data, indent=4))

        print(f"✅ Saved JSON for '{project_name}' at: {json_file.resolve()}")

    except Exception as e:
        print(f"❌ Failed to save JSON for '{project_name}': {e}")

# Handle empty Projects folder
if not any(projects_dir.iterdir()):
    print("⚠️ Projects folder is empty. Create subfolders for your projects and rerun the script.")
