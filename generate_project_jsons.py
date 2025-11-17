import os
import json

# Paths
projects_dir = "Projects"
readme_path = "README.md"

# Placeholder in README
placeholder = "<!-- PROJECT-LIST-AUTO -->"

# Default values
default_description = "This project showcases technical skills and applied knowledge in engineering, electronics, and software development."
default_tech = ["ESP32", "Raspberry Pi", "Python", "Other relevant tech"]
default_status = "Completed"

# Ensure Projects folder exists
os.makedirs(projects_dir, exist_ok=True)

# Loop over all items in Projects folder
for project_name in os.listdir(projects_dir):
    # Skip non-folders
    project_path = os.path.join(projects_dir, project_name)
    if not os.path.isdir(project_path):
        continue

    # Ensure JSON exists and update it
    json_path = os.path.join(project_path, f"{project_name}.json")
    if os.path.exists(json_path):
        with open(json_path, "r") as f:
            project_data = json.load(f)
    else:
        project_data = {}

    project_data["name"] = project_name
    project_data["description"] = project_data.get("description", default_description)
    project_data["tech"] = project_data.get("tech", default_tech)
    project_data["status"] = project_data.get("status", default_status)

    # Write JSON
    with open(json_path, "w") as f:
        json.dump(project_data, f, indent=4)

print("Project JSONs created/updated successfully!")

# Generate README
project_entries = []

for project_name in os.listdir(projects_dir):
    project_path = os.path.join(projects_dir, project_name)
    json_path = os.path.join(project_path, f"{project_name}.json")
    if os.path.exists(json_path):
        with open(json_path, "r") as f:
            data = json.load(f)
        entry = f"### {data['name']}\n\n" \
                f"{data['description']}\n\n" \
                f"**Tech used:** {', '.join(data['tech'])}\n\n" \
                f"**Status:** {data['status']}\n"
        project_entries.append(entry)

projects_md = "\n---\n".join(project_entries)

# Read or create README
if os.path.exists(readme_path):
    with open(readme_path, "r") as f:
        content = f.read()
else:
    content = f"# My Portfolio\n\n{placeholder}\n"

# Replace placeholder with projects list
if placeholder in content:
    content = content.replace(placeholder, projects_md)
else:
    content += "\n\n" + projects_md

# Write README
with open(readme_path, "w") as f:
    f.write(content)

print("README updated successfully!")
