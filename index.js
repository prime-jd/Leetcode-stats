const express = require('express');
const axios = require('axios');

const app = express();
const PORT = process.env.PORT || 3000;

app.get('/leetcode/:username', async (req, res) => {
    const username = req.params.username;
    const url = `https://alfa-leetcode-api.onrender.com/${username}/solved`;  // Replace with your actual API endpoint

    try {
        const response = await axios.get(url);
        const data = response.data;

        const easy = data.easySolved || 0;
        const medium = data.mediumSolved || 0;
        const hard = data.hardSolved || 0;

        const maxValue = Math.max(easy, medium, hard, 1);
        const easyHeight = (easy / maxValue) * 200;  // Adjusted to make the SVG smaller
        const mediumHeight = (medium / maxValue) * 200;
        const hardHeight = (hard / maxValue) * 200;

        const svg = `
        <svg viewBox="0 0 400 400" xmlns="http://www.w3.org/2000/svg">
            <!-- Background -->
            <rect width="100%" height="100%" fill="#f0f0f0"/>

            <!-- Bars -->
            <rect x="60" y="${300 - easyHeight}" width="60" height="${easyHeight}" fill="green" class="bar">
                <title>Easy: ${easy}</title>
            </rect>
            <rect x="170" y="${300 - mediumHeight}" width="60" height="${mediumHeight}" fill="orange" class="bar">
                <title>Medium: ${medium}</title>
            </rect>
            <rect x="280" y="${300 - hardHeight}" width="60" height="${hardHeight}" fill="red" class="bar">
                <title>Hard: ${hard}</title>
            </rect>

            <!-- Labels -->
            <text x="90" y="350" font-size="18" fill="black" text-anchor="middle">Easy</text>
            <text x="200" y="350" font-size="18" fill="black" text-anchor="middle">Medium</text>
            <text x="310" y="350" font-size="18" fill="black" text-anchor="middle">Hard</text>

            <!-- Count Labels -->
            <text x="90" y="${300 - easyHeight - 10}" font-size="16" fill="black" text-anchor="middle">${easy}</text>
            <text x="200" y="${300 - mediumHeight - 10}" font-size="16" fill="black" text-anchor="middle">${medium}</text>
            <text x="310" y="${300 - hardHeight - 10}" font-size="16" fill="black" text-anchor="middle">${hard}</text>

            <!-- Animation -->
            <style>
                .bar {
                    animation: grow 1s ease-out forwards;
                }

                @keyframes grow {
                    from { height: 0; }
                    to { height: 100%; }
                }
            </style>
        </svg>`;

        res.setHeader('Content-Type', 'image/svg+xml');
        res.send(svg);
    } catch (error) {
        res.status(500).send(`Error fetching data for ${username}: ${error.message}`);
    }
});

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
