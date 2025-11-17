from pathlib import Path
import json

# Root Projects folder (relative to script)
projects_root = Path("Projects")

# Iterate through each subfolder in Projects
for project_folder in projects_root.iterdir():
    if project_folder.is_dir():
        # JSON filename = project folder name
        json_file = f"{projects_folder.name}/{project_folder.name}.json"

        # Example project data (update as needed)
        project_data = {
            "name": project_folder.name,
            "description": "This project showcases technical skills and applied knowledge in engineering, electronics, and software development.",
            "techs": ["ESP32", "Raspberry Pi", "Python", "Other relevant tech"],
            "status": "completed"
        }

        # Ensure folder exists (safety)
        project_folder.mkdir(parents=True, exist_ok=True)

        # Write JSON
        with open(json_file, "w") as f:
            json.dump(project_data, f, indent=4)

        #print(f"Created JSON: {json_file.resolve()}")
