from pathlib import Path
import json

# Root Projects folder (relative to script)
projects_root = Path("Projects")

# Iterate through each subfolder in Projects
for project_folder in projects_root.iterdir():
    if project_folder.is_dir():
        # JSON filename = project folder name
        json_file = f"{project_root.name}/{project_folder.name}.json"

        # Example project data (update as needed)
        project_data = {
            "name": project_folder.name,
            "description": "General project description",
            "status": "completed"
        }

        # Ensure folder exists (safety)
        project_folder.mkdir(parents=True, exist_ok=True)

        # Write JSON
        with open(json_file, "w") as f:
            json.dump(project_data, f, indent=4)

        print(f"Created JSON: {json_file.resolve()}")
