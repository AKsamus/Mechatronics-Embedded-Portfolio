from pathlib import Path
import json

# Root Projects folder (relative to script)
projects_root = Path("Projects")

# Iterate through each subfolder in Projects
for project_folder in projects_root.iterdir():
    if project_folder.is_dir():
        # JSON filename = project folder name
        file_path = f"{projects_root.name}/{project_folder.name}.json"
        if Path(file_path).exists():
            continue  # Skip if JSON already exists
        else:
            # Example project data (update as needed)
            project_data = {
                "name": project_folder.name,
                "description": "This project showcases technical skills and applied knowledge in engineering, electronics, and software development.",
                "techs": [],
                "status": "In Progress"
            }

            # Ensure folder exists (safety)
            project_folder.mkdir(parents=True, exist_ok=True)

            # Write JSON
            with open(json_file, "w") as f:
                json.dump(project_data, f, indent=4)

            #print(f"Created JSON: {json_file.resolve()}")
